int findFirstOccurrence(const vector<int>& A, int B) 
{
    int low = 0;
    int high = A.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == B) {
            result = mid;
            high = mid - 1;
        } else if (A[mid] < B) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int findLastOccurrence(const vector<int>& A, int B) 
{
    int low = 0;
    int high = A.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == B) {
            result = mid;
            low = mid + 1;
        } else if (A[mid] < B) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}


vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int first = findFirstOccurrence(A, B);
    int last = findLastOccurrence(A, B);

    return {first, last};
}
