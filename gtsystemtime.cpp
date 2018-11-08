//Get the current system time

        struct timeval tp;
        gettimeofday(&tp, NULL);
        long int ms1 = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        std::cout << ms1 << std::endl;
