#include "Resources.h"

	typedef std::function<void()> Event;

	Resources::Resources(std::string s){inUse = false; name = s;counter = 0; k =100;}
	Resources& Resources::operator=(const Resources &rhs){
		if(&rhs == this) return *this;
		name = rhs.identity();
		inUse = rhs.resourceCheck();
		q = rhs.currentQueue();
		return *this;
	}
	Resources::Resources(const Resources &rhs){
		name = rhs.identity();
		inUse = rhs.resourceCheck();
		q = rhs.currentQueue();
	}
	int Resources::size() { return q.size();}
	bool Resources::reserve (){ 
		if(inUse) return false;
		else{
			inUse = true;
			return true;

		}
	}

	std::queue<Event> Resources::currentQueue () const{
		return q;
	}

	std::string Resources::identity() const{
		
		return name;
	}
	bool Resources::resourceCheck() const{
		return inUse;
	}

	void Resources::acquire (Event e){
		if (! inUse){
			counter++;
			if(counter==k)
				inUse = true;
			sim::post(0,e);
		}
		else 
			q.push(e);
	}

	void Resources::release() {
		if(!q.empty()){
	
			Event e = q.front();

			q.pop();
			sim::post (0,e);
		}
		else{
			inUse = false;
			counter--;
		}

	}

	int Resources::resourceOccupation(){
		return counter;
	}
	
