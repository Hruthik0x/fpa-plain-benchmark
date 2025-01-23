`gcc -O0 benchmark.c && ./a.out`

Output : 
```
----------------------Benchmarking store functions----------------------

Total time Hruthik's sol : 0.492564
Avg per round (1000 rounds) : 0.000493

Total time Saurabh's sol : 0.500290
Avg per round (1000 rounds) : 0.000500


-----------------------Benchmarking add functions-----------------------

Total time Hruthik's sol : 0.008915
Avg per round (500000 rounds) : 0.000000

Total time Saurabh's sol : 0.008404
Avg per round (500000 rounds) : 0.000000

-------------------Benchmarking retrieval functions-------------------

Total time Hruthik's sol : 0.030000
Avg per round (500000 rounds) : 0.000000

Total time Saurabh's sol : 0.028325
Avg per round (500000 rounds) : 0.000000
```

- In case of storing, Hruthik's sol is faster as it involve 1 less multiplication. (mul by 100)
- In case of addition, Hruthik's sol is slower as it needs explicit management of overflow.(if float part > 100)
- In case of retrieval Hruthik's sol is quicker as it does not need additional arithmetic calcs (%100 and /100) like Saurabh sol does.