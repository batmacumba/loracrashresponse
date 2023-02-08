# eXtreme Go Horse Methodology ;)

NUMBER_OF_ESSAYS = 30.0
import statistics as stats
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

coverage = []
for r in results:
    coverage.append(float(len(r) / 10.0))

print('10 ' + str(stats.mean(coverage)))
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

coverage = []
for r in results:
    coverage.append(float(len(r) / 20.0))

print('20 ' + str(stats.mean(coverage)))
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

coverage = []
for r in results:
    coverage.append(float(len(r) / 40.0))

print('40 ' + str(stats.mean(coverage)))
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

coverage = []
for r in results:
    coverage.append(float(len(r) / 80.0))

print('80 ' + str(stats.mean(coverage)))
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

coverage = []
for r in results:
    coverage.append(float(len(r) / 160.0))

print('160 ' + str(stats.mean(coverage)))
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

coverage = []
for r in results:
    coverage.append(float(len(r) / 320.0))

print('320 ' + str(stats.mean(coverage)))
################################################################################