# Merge Sort
def merge_sort(arr):
    if len(arr) > 1:
        # Divide
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]
        
        merge_sort(L)
        merge_sort(R)
        
        #Merging
        i = j = k = 0
        
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
               arr[k] = L[i]
               i += 1
           else:
               arr[k] = R[j]
               j += 1
            k += 1
            
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
            
        while i < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
        
    return arr

merge_sort([10, 7, 8, 9, 1, 5])