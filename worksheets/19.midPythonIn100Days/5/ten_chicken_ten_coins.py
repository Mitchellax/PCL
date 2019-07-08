#! python3
for num_cock in range (0, 100):
    for num_hen in range (0, 100):
        if 14*num_cock + 8*num_hen -200 == 0 and 100 - num_hen - num_cock >= 0:
            print("There are ", num_cock, " cocks, ", num_hen, " hens and ", (100 - num_cock - num_hen), " chicks")