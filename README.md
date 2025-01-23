`gcc -O0 benchmark.c && ./a.out`

Output : 
```
----------------------Benchmarking store functions----------------------

Total time Hruthik's sol : 0.506968
Avg per round (1000 rounds) : 0.000507

Total time Saurabh's sol : 0.540768
Avg per round (1000 rounds) : 0.000541


-----------------------Benchmarking add functions-----------------------

Total time Hruthik's sol : 0.009044
Avg per round (500000 rounds) : 0.000000

Total time Saurabh's sol : 0.006737
Avg per round (500000 rounds) : 0.000000

-------------------Benchmarking retrieval functions-------------------

Total time Hruthik's sol : 0.027399
Avg per round (500000 rounds) : 0.000000

Total time Saurabh's sol : 0.027737
Avg per round (500000 rounds) : 0.000000
```

- In case of storing, Hruthik's sol is faster as it involve 1 less multiplication. (mul by 100)
- In case of addition, Hruthik's sol is slower as it needs explicit management of overflow.(if float part > 100)
- In case of retrieval Hruthik's sol is quicker as it does not need additional arithmetic calcs (%100 and /100) like Saurabh sol does.