#pragma once
#include "AbstractList.h"
#include <stdexcept>

template <typename T> class ArrayList : AbstractList<T>
{
private:
	T* listArray;
	int maxSize;
	int currentSize;
	int currentPosition;

public:
	ArrayList(int size)
	{
		maxSize = size;
		currentPosition = 0;
		currentSize = 0;
		listArray = new T[size];
	}

	~ArrayList()
	{
		delete []listArray;
	}

	// Insert element at the current positon.
	virtual void insert(const T& element)
	{
		if (currentSize < maxSize)
		{
			for (int i = currentSize - 1; i >= currentPosition; i--)
			{
				listArray[i] = listArray[i - 1];
			}
			listArray[currentPosition] = element;
			currentSize++;
		}
		else
		{
			throw std::range_error("List capacity has been reached.");
		}
		
	}
	
	// Remove the element at the current position and return it.
	virtual T remove()
	{
		T removedElement = listArray[currentPosition];
		for (int i = currentPosition; i < currentSize; i++)
		{
			listArray[i] = listArray[i + 1];
		}
		currentSize--;
		return removedElement;
	}

	// Add an element to the end of the list.
	virtual void append(const T& element)
	{
		if (currentSize < maxSize)
		{
			listArray[currentSize] = element;
			currentSize++;
		}
	}

	// Clear the list of all elements.
	virtual void clear()
	{
		delete listArray;
		currentPosition = 0;
		currentSize = 0;
		listArray = new T[maxSize];
	}

	// Move to the start of the list.
	virtual void moveToStart()
	{
		currentPosition = 0;
	}

	// Move to the end of the list.
	virtual void moveToEnd()
	{
		currentPosition = currentSize;
	}

	// Move to the next element.
	virtual void next()
	{
		if (currentPosition < currentSize)
		{
			currentPosition++;
		}	
		else
		{
			throw new std::range_error("No further elements exist.");
		}
	}

	// Move to the previous element.
	virtual void previous()
	{
		if (currentPosition > 0)
		{
			currentPosition--;
		}
		else
		{
			throw new std::range_error("Cannot preceed beginning of list.");
		}
		
	}

	// Return an integer representing the current position in the list.
	virtual int getCurrentPos()
	{
		return currentPosition;
	}

	// Move to the position designated by the position parameter.
	virtual void moveToPosition(int position)
	{
		if (position < 0 || position >= maxSize)
		{
			throw new std::range_error("No such list element.");
		}
		else
		{
			currentPosition = position;
		}
	}

	// Return the element currently pointed to without removing it.
	virtual const T& getElement() const
	{
		return listArray[currentPosition];
	}

	// Return the current number of elements in the list.
	virtual int length()
	{
		return currentSize;
	}

};

