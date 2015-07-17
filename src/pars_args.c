int pars_args(int argc, char* argv[])
{
	if ((argc < 3) || (argc>4))
		return -1; // wrong number of arguments
	else
		if (argv[1][0] != '-')
			return -2; // wrong parameter
		else
			if ((strcmp(argv[1], "-a") == 0) || (strcmp(argv[1], "--alphabet") == 0))
				return 1; // alphabetic order
			else
				if ((strcmp(argv[1], "-i") == 0) || (strcmp(argv[1], "--ignorecase") == 0))
					return 2; // ignorecase
				else
					if ((strcmp(argv[1], "-i-r") == 0) || (strcmp(argv[1], "-r-i") == 0) || (strcmp(argv[1], "-ir") == 0) || (strcmp(argv[1], "-ri") == 0))
						return 3; // ignorecase + reverse
					else
						if ((strcmp(argv[1], "-a-r") == 0) || (strcmp(argv[1], "-r-a") == 0) || (strcmp(argv[1], "-ra") == 0) || (strcmp(argv[1], "-ar") == 0))
							return 4; // alphabetic + reverse
						else
							if ((strcmp(argv[1], "-R") == 0) || (strcmp(argv[1], "--random") == 0))
								return 5; // random
							else
								if (strcmp(argv[1], "--help") == 0)
									return 6; // help
								else
									if (strcmp(argv[1], "--version") == 0)
										return 7; // version
									else
										return -3; // wrong parameter
}
