//Write a function subsets that finds every possible sub-list of a
//given vector. A sub-list of a vector V contains ≥ 0 of V's elements
/*
Example: if V is {Jane, Bob, Matt, Sara},
then the call of subsets(V); prints:
{Jane, Bob, Matt, Sara} {Bob, Matt, Sara}
{Jane, Bob, Matt} {Bob, Matt}
{Jane, Bob, Sara} {Bob, Sara}
{Jane, Bob} {Bob}
{Jane, Matt, Sara} {Matt, Sara}
{Jane, Matt} {Matt}
{Jane, Sara} {Sara}
{Jane} {}
*/
//pseudo codes using set
//here the best recursive tree is to check if every element gets to exist or not
//iterate for all possible combinations

void subSets(set<string>& masterSet)
{
    set<string> chosen; //a set where the temporary subsets are stored
    listSubsetsRec(masterSet, chosen);
}
void listSubsetsRec(set<string>& masterSet, set<string>& used) {
    if (masterSet.isEmpty())
    {
        cout << used << endl;
    }
    else
    {
        string element = masterSet.first();
        masterSet.remove(element);
        listSubsetsRec(masterSet, used); // Without
        used.add(element);
        listSubsetsRec(masterSet, used); // With
        masterSet.add(element);
        used.remove(element);
    }
}

