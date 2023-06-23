// https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/

int majorityElement(vector<int> v) {
	// Write your code here
	int c=1,ele=v[0];
	for(int i=1;i<v.size();i++)
	{
		if(v[i]==ele)	c++;
		else{
			c--;
		}
		if(c==0){
			c=1;
			ele=v[i];
		}
	}
	c=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==ele)
			c++;
	}
	if(c>v.size()/2);
		return ele;
	return -1;
}
