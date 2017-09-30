# Linear Time Sorting

### Variant №9-1:
Key type: double [-100; 100]  </br>
Data type: string </br>
Sort method: bucket sort
### Algorithm of Bucket sort:
```
double[] bucketSort(double[] array) 
   minElement = Infinum
   maxElement = -Infinum
   for i = 0 to array.length - 1
       minElement = minimum(minElement, array[i])
       maxElement = maximum(maxElement, array[i]) 
   range = maxElement - minElement
   for i = 0  to array.length - 1  
       index = int(array[i] * numBuckets / range)
       add array[i] to buckets[index]
   for i = 0 to numBuckets - 1
       buckets[i] = sort(buckets[i])
   for i = 0 to numBuckets - 1
       for k = 0 to buckets[i].length - 1
          add buckets[i][k] to answer
   return answer
```
### Structure Realization
...
