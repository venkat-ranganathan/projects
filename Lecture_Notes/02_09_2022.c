// discussing how to determine complexity of algorithm by calculating how many times each line runs, and total number of lines run
// code is intentionally non-functioning

for(int i = 0; i < n; i++)
{
    if(i % 10 == 0)
        break;
    printf("%d", i);
    p = p + i;
}

for(int i = 0; i < n; i++) // n + 1 times executed; n + 1
    for(int j = 0; j < n; j++) // n( n + 1) times executed; n^2 + n
        printf(...); // n( n ) times executed; n^2
        // total is 2n^2 + 2n + 1
        // Big-O complexity: O(n^2)  since n^2 is the most complex term