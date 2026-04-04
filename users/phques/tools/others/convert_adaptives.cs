// Convert JSON adaptive trigger pairs into QMK adaptive_3key_t/adaptive_2key_t tables.
// Usage: cat rules.json | dotnet run --project convert_adaptives.csproj
// Or compiled: cat rules.json | ./convert_adaptives

using System.Text.Json;

var special = new Dictionary<char, string>
{
    ['.']  = "KC_DOT",
    ['/']  = "KC_SLASH",
    ['"']  = "KC_DQUO",
    ['\''] = "KC_QUOTE",
    ['#']  = "KC_HASH",
};

string KeycodeForChar(char ch)
{
    char lower = char.ToLower(ch);
    if (lower >= 'a' && lower <= 'z')
        return "KC_" + char.ToUpper(lower);
    if (special.TryGetValue(lower, out var kc))
        return kc;
    throw new ArgumentException($"Unsupported key char: '{ch}'");
}

string CEscape(string s) =>
    s.Replace("\\", "\\\\").Replace("\"", "\\\"");

string MappingComment(string trigger, string output) =>
    $"// {trigger} -> {output}";

string FormatEntry(string entry, string comment, int width)
{
    var withComma = (entry + ",").PadRight(width + 1);
    return $"    {withComma} {comment}";
}

List<(string trigger, string output)> ParseRules(string input)
{
    var data = JsonSerializer.Deserialize<List<List<string>>>(input)
        ?? throw new InvalidOperationException("Top-level JSON must be an array");

    var parsed = new List<(string, string)>();
    foreach (var item in data)
    {
        if (item.Count != 2)
            throw new ArgumentException($"Each row must be [trigger, output], got: [{string.Join(", ", item)}]");

        var trig = item[0];
        var output = item[1];

        if (trig.Length != 2 && trig.Length != 3)
            throw new ArgumentException($"Trigger must be length 2 or 3, got: \"{trig}\"");

        parsed.Add((trig, output));
    }
    return parsed;
}

void EmitAdaptiveTables(List<(string trigger, string output)> rules)
{
    var threeKey = rules.Where(r => r.trigger.Length == 3).ToList();
    var twoKey   = rules.Where(r => r.trigger.Length == 2).ToList();

    var threePrefixes = new HashSet<(char, char)>(
        threeKey.Select(r => (r.trigger[0], r.trigger[1])));

    var threeEntries = threeKey
        .Select(r => (
            entry:   $"{{{KeycodeForChar(r.trigger[0])}, {KeycodeForChar(r.trigger[1])}, {KeycodeForChar(r.trigger[2])}, \"{CEscape(r.output)}\"}}",
            comment: MappingComment(r.trigger, r.output)))
        .ToList();

    var twoEntries = twoKey
        .Select(r => (
            entry:   $"{{{KeycodeForChar(r.trigger[0])}, {KeycodeForChar(r.trigger[1])}, \"{CEscape(r.output)}\"}}",
            comment: MappingComment(r.trigger, r.output)))
        .ToList();

    int threeWidth = threeEntries.Count > 0 ? threeEntries.Max(e => e.entry.Length) : 0;
    int twoWidth   = twoEntries.Count   > 0 ? twoEntries.Max(e => e.entry.Length)   : 0;

    Console.WriteLine("// Auto-generated adaptive key tables. Do not edit directly.");
    Console.WriteLine("#include <quantum.h>");
    Console.WriteLine();
    Console.WriteLine("#include \"../../processAdaptive.h\"");
    Console.WriteLine();
    Console.WriteLine("const adaptive_3key_t adaptive_3keys[] PROGMEM = {");
    foreach (var (entry, comment) in threeEntries)
        Console.WriteLine(FormatEntry(entry, comment, threeWidth));
    Console.WriteLine("    {0, 0, 0, NULL}");
    Console.WriteLine("};");
    Console.WriteLine();

    Console.WriteLine("const adaptive_2key_t adaptive_2keys[] PROGMEM = {");
    foreach (var (entry, comment) in twoEntries)
        Console.WriteLine(FormatEntry(entry, comment, twoWidth));
    Console.WriteLine("    {0, 0, NULL}");
    Console.WriteLine("};");

    var conflicts = twoKey
        .Where(r => threePrefixes.Contains((r.trigger[0], r.trigger[1])))
        .OrderBy(r => r.trigger)
        .ToList();

    if (conflicts.Count > 0)
    {
        Console.Error.WriteLine();
        Console.Error.WriteLine("WARNING: Shared-prefix conflicts found:");
        foreach (var r in conflicts)
            Console.Error.WriteLine($"  2-key trigger \"{r.trigger}\" -> \"{r.output}\" shares prefix with a 3-key trigger.");
    }
}

try
{
    var input = Console.In.ReadToEnd();
    var rules = ParseRules(input);
    EmitAdaptiveTables(rules);
}
catch (Exception ex)
{
    Console.Error.WriteLine($"Error: {ex.Message}");
    Environment.Exit(1);
}
