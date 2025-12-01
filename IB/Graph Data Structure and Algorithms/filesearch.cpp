//not working

int findParent(int id, unordered_map<int, int>& parent) 
{
    if (parent[id] != id) 
    {
        parent[id] = findParent(parent[id], parent);
    }
    return parent[id];
}

int Solution::breakRecords(int A, vector<vector<int> > &B) {
    unordered_map<int, int> parent;

    for (const auto& record : B) 
    {
        int id = record[0];
        int parentID = record[1];

        if (parent.find(id) == parent.end()) {
            parent[id] = id;
        }
        if (parent.find(parentID) == parent.end()) {
            parent[parentID] = parentID;
        }

        int rootID = findParent(id, parent);
        int rootParentID = findParent(parentID, parent);

        if (rootID != rootParentID) {
            parent[rootParentID] = rootID;
        }
    }

    unordered_map<int, bool> rootParents;
    for (const auto& pair : parent) 
    {
        int id = pair.first;
        int rootParent = findParent(id, parent);
        rootParents[rootParent] = true;
    }

    return rootParents.size();
}
