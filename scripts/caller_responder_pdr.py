# eXtreme Go Horse Methodology ;)
NUMBER_OF_ESSAYS = 30.0

################################################################################
f = open("../../data/10", "r")
raw = []
for line in f.read().split("\n\n"):
    raw.append(line)

results = []
i = 0
for test in raw:
    nodes = test.split("\n")
    results.append({})
    for n in nodes:
        value_key = n.split()
        results[i][value_key[1]] = value_key[0]
    i += 1

test_succeeded_n = 0
for r in results:
    if '9' in r:
        test_succeeded_n += 1

print('10 ' + str(test_succeeded_n / NUMBER_OF_ESSAYS))
################################################################################

################################################################################
f = open("../../data/20", "r")
raw = []
for line in f.read().split("\n\n"):
    raw.append(line)

results = []
i = 0
for test in raw:
    nodes = test.split("\n")
    results.append({})
    for n in nodes:
        value_key = n.split()
        results[i][value_key[1]] = value_key[0]
    i += 1

test_succeeded_n = 0
for r in results:
    if '19' in r:
        test_succeeded_n += 1

print('20 ' + str(test_succeeded_n / NUMBER_OF_ESSAYS))
################################################################################

################################################################################
f = open("../../data/40", "r")
raw = []
for line in f.read().split("\n\n"):
    raw.append(line)

results = []
i = 0
for test in raw:
    nodes = test.split("\n")
    results.append({})
    for n in nodes:
        value_key = n.split()
        results[i][value_key[1]] = value_key[0]
    i += 1

test_succeeded_n = 0
for r in results:
    if '39' in r:
        test_succeeded_n += 1

print('40 ' + str(test_succeeded_n / NUMBER_OF_ESSAYS))
################################################################################

################################################################################
f = open("../../data/80", "r")
raw = []
for line in f.read().split("\n\n"):
    raw.append(line)

results = []
i = 0
for test in raw:
    nodes = test.split("\n")
    results.append({})
    for n in nodes:
        value_key = n.split()
        results[i][value_key[1]] = value_key[0]
    i += 1

test_succeeded_n = 0
for r in results:
    if '79' in r:
        test_succeeded_n += 1

print('80 ' + str(test_succeeded_n / NUMBER_OF_ESSAYS))
################################################################################

################################################################################
f = open("../../data/160", "r")
raw = []
for line in f.read().split("\n\n"):
    raw.append(line)

results = []
i = 0
for test in raw:
    nodes = test.split("\n")
    results.append({})
    for n in nodes:
        value_key = n.split()
        results[i][value_key[1]] = value_key[0]
    i += 1

test_succeeded_n = 0
for r in results:
    if '159' in r:
        test_succeeded_n += 1

print('160 ' + str(test_succeeded_n / NUMBER_OF_ESSAYS))
################################################################################

################################################################################
f = open("../../data/320", "r")
raw = []
for line in f.read().split("\n\n"):
    raw.append(line)

results = []
i = 0
for test in raw:
    nodes = test.split("\n")
    results.append({})
    for n in nodes:
        value_key = n.split()
        results[i][value_key[1]] = value_key[0]
    i += 1

test_succeeded_n = 0
for r in results:
    if '319' in r:
        test_succeeded_n += 1

print('320 ' + str(test_succeeded_n / NUMBER_OF_ESSAYS))
################################################################################