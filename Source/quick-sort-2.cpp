// Ascending Order
void quick_sort(int p ,vector<int> &c)
{
    vector<int> lft,rgt,mid;
    for(auto &i :c)
    {
        if (i<p)    lft.push_back(i);
        else if(i>p)    rgt.push_back(i);
        else mid.push_back(i);
    }
    if(!lft.empty())    quick_sort(lft[0], lft);
    if(!rgt.empty())    quick_sort(rgt[0], rgt);
    c.clear();
    c.insert(c.end(),lft.begin(),lft.end());
    c.insert(c.end(),mid.begin(),mid.end());
    c.insert(c.end(),rgt.begin(),rgt.end());
}