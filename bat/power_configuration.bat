@echo Setup power configuration
Powercfg -SETACTIVE SCHEME_MIN
powercfg -setacvalueindex scheme_current sub_processor 0cc5b647-c1df-4637-891a-dec35c318583 100
powercfg -setactive scheme_current
