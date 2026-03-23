PYTHON ?= python3

ADAPT_JSON := layouts/hd-pm/hd-pm-adapt.json
ADAPT_HDR := layouts/hd-pm/hd-pm-adaptives.h
ADAPT_TOOL := tools/convert_adaptives.py

.PHONY: adaptives

adaptives: $(ADAPT_HDR)

$(ADAPT_HDR): $(ADAPT_JSON) $(ADAPT_TOOL)
	@tmp="$@.tmp"; \
	$(PYTHON) $(ADAPT_TOOL) < "$<" > "$$tmp" && mv "$$tmp" "$@"