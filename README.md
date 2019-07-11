# find_peak

The output of peak count is 4.
```
 - gcc -o main main.c

 - ./main
```

<img src = "https://i.imgur.com/9uw3cuX.png" width=600>

There are two parameters need to be set:

1. param_uphill_threshold: set the threshold to trigger.(default=150)

2. param_downhill_cnt_limit: when over threshold, check the next frame whether it's higher data. It means the number of checking frame (default=10). 
