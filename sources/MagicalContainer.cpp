#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

//Helpers

void MagicalContainer::updateSorted()
{
	_elementSorted.clear();
	for (auto it = _elements.begin(); it != _elements.end(); ++it)
	{
		_elementSorted.push_back(&(*it));
	}	
}

void MagicalContainer::updatePrime()
{
	_elementsPrime.clear();
	for (auto it = _elements.begin(); it != _elements.end(); ++it)
	{
		if (isPrime(*it))
		{
			_elementsPrime.push_back(&(*it));
		}
	}	
}

void MagicalContainer::updateCross()
{	
	_elementsCross.clear();
    auto start = _elements.begin();
    auto end = _elements.end() - 1;

    while (start <= end)
    {
        _elementsCross.push_back(&(*start));
        if (start != end)
            _elementsCross.push_back(&(*end));
        start++;
        end--;
    }
}

bool MagicalContainer::isPrime(int element)
{
	if (element < 2) {
        return false;
    }
    
    if (element == 2 || element == 3) {
        return true;
    }
    
    if (element % 2 == 0 || element % 3 == 0) {
        return false;
    }
    
    int divisor = 5;
    int limit = sqrt(element);
    
    while (divisor <= limit) {
        if (element % divisor == 0 || element % (divisor + 2) == 0) {
            return false;
        }
        divisor += 6;
    }
    
    return true;
}

//MagicalContainer

void MagicalContainer::addElement(int element)
{   
	_elements.push_back(element);
	sort(_elements.begin(), _elements.end());

	updateSorted();
	updatePrime();
	updateCross();
}

void MagicalContainer::removeElement(int element)
{
	bool flag = false;
	for (auto it = _elements.begin(); it != _elements.end(); ++it)
	{
		if (*it == element)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		throw std::runtime_error("Could not find argument to remove");
	}

	_elements.erase(std::remove(_elements.begin(), _elements.end(), element), _elements.end());
	updateSorted();
	updatePrime();
	updateCross();

}

size_t MagicalContainer::size()
{
	return _elements.size();
}

//AscendingIterator

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container), iter(container._elementSorted.begin()), pos(0) 
{

}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(other.container), iter(other.iter), pos(other.pos) 
{
	
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
{
	if(&container != &other.container)
	{
		throw std::runtime_error("Both atguments must be in the same container");
	}

	iter = other.iter;
	pos = other.pos;

	return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
	if(iter == container._elementSorted.end())
	{
		throw std::runtime_error("Index is out of range");
	}

	++iter;
	++pos;

	return *this;
}

int MagicalContainer::AscendingIterator::operator*()
{
	if(iter == container._elementSorted.end())
	{
		throw std::out_of_range("Index is out of range");
	}

	return **iter;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
{
	if(&container != &other.container)
	{
		throw std::invalid_argument("Both atguments must be in the same container");
	}

	return pos == other.pos;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
	return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
{
	if(&container != &other.container)
	{
		throw std::invalid_argument("Both atguments must be in the same container");
	}

	return pos < other.pos;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
	if(&container != &other.container) // if they are not the same container
	{
		throw std::invalid_argument("Both atguments must be in the same container");
	}
	return pos > other.pos;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin()
{
	iter = container._elementSorted.begin();
	pos = 0;

	return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end()
{
	iter = container._elementSorted.end();
	pos = container._elementSorted.size();
	return *this;
}

//SideCrossIterator

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container(container), iter(container._elementsCross.begin()), pos(0) 
{

}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : container(other.container), iter(other.iter), pos(other.pos) 
{

}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
{
	if(&container != &other.container)
	{
		throw std::runtime_error("Both atguments must be in the same container");
	}

	iter = other.iter;
	pos = other.pos;

	return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
	if(iter == container._elementsCross.end())
	{
		throw std::runtime_error("Index is out of range");
	}

	++iter;
	++pos;

	return *this;
}

int& MagicalContainer::SideCrossIterator::operator*()
{
	if(iter == container._elementsCross.end())
	{
		throw std::out_of_range("Index is out of range");
	}

	return **iter;
}


bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
{
	if(&container != &other.container)
	{
		throw std::invalid_argument("Both atguments must be in the same container");
	}
	return pos == other.pos;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
{
	return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
{
	if(&container != &other.container)
	{
		throw std::invalid_argument("Both atguments must be in the same container");
	}

	return pos < other.pos;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
{
	if(&container != &other.container)
	{
		throw std::invalid_argument("Both atguments must be in the same container");
	}

	return pos > other.pos;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin()
{
	iter = container._elementsCross.begin(); 
	pos = 0;

	return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end()
{
	iter = container._elementsCross.end(); 
	pos = container._elementsCross.size();

	return *this;
}

//PrimeIterator

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : container(container), iter(container._elementsPrime.begin()), pos(0) 
{

}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : container(other.container), iter(other.iter), pos(other.pos) 
{

}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
{
	if(&container != &other.container)
	{
		throw std::runtime_error("Both atguments must be in the same container");
	}

	iter = other.iter;
	pos = other.pos;

	return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
	if(iter == container._elementsPrime.end())
	{
		throw std::runtime_error("Index out of range");
	}

	++iter;
	++pos;

	return *this;
}

int& MagicalContainer::PrimeIterator::operator*()
{   
	if(iter == container._elementsPrime.end())
	{
		throw std::out_of_range("Index out of range");
	}
	return **iter;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const
{
	if(&container != &other.container)
	{
		throw std::invalid_argument("Both atguments must be in the same container");
	}
	return pos == other.pos;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
{
	return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
{
	if(&container != &other.container)
	{
		throw std::invalid_argument("Both atguments must be in the same container");
	}

	return pos < other.pos;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
{
	if(&container != &other.container)
	{
		throw std::invalid_argument("Both atguments must be in the same container");
	}

	return pos > other.pos;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin()
{
	iter = container._elementsPrime.begin();
	pos = 0;                           
	return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end()
{
	iter = container._elementsPrime.end();
	pos = container._elementsPrime.size();
	return *this;
}
