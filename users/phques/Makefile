PYTHON ?= python3

ADAPT_TOOL := tools/convert_adaptives.py

ADAPT_JSON := layouts/sunlight/sunlight-adapt-c.json
ADAPT_HDR := layouts/sunlight/sunlight-adaptives-c.h
# ADAPT_JSON := layouts/hd-pm/hd-pm-adapt.json
# ADAPT_HDR := layouts/hd-pm/hd-pm-adaptives.h
# ADAPT_JSON := layouts/nordrassil/nordrassil-adapt.json
# ADAPT_HDR :=  layouts/nordrassil/nordrassil-adaptives.h

.PHONY: adapt

adapt: $(ADAPT_HDR)

$(ADAPT_HDR): $(ADAPT_JSON) $(ADAPT_TOOL)
	@tmp="$@.tmp"; \
	$(PYTHON) $(ADAPT_TOOL) < "$<" > "$$tmp" && mv "$$tmp" "$@"