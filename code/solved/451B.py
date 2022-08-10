input()
arr = list(map(int, input().split()))
# From Start
end = -1
start = -1
last = 0
for i in range(1, len(arr)):
    if arr[i] < arr[last]:
        end = last
        break
    last = i
# From End
last = len(arr)-1
for i in range(len(arr)-1, -1, -1):
    if arr[i] > arr[last]:
        start = last
        break
    last = i
reversed = arr.copy()
rev = arr[end:start+1]
reversed[end:start+1] = rev[::-1]
if sorted(arr) == reversed:
    print("yes")
    if start == end:
        print(1, 1)
    else:
        print(end+1, start+1)
else:
    print("no")
# Check if possible