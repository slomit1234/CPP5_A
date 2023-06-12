#pragma once

#include <math.h>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <set>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {

        private:
            vector<int> _elements;
            vector<int*> _elementSorted;
            vector<int*> _elementsCross;
            vector<int*> _elementsPrime;

			//Helpers
            void updateCross();
            void updatePrime();
            void updateSorted();
			static bool isPrime(int element);

        public:
            void addElement(int element);
            void removeElement(int element);
			size_t size();

        class AscendingIterator
        {
            private:
                MagicalContainer& container;
                vector<int*>::iterator iter;
                size_t pos;

            public:
                AscendingIterator(MagicalContainer& container);
                AscendingIterator(const AscendingIterator& other);

                ~AscendingIterator() = default;

                AscendingIterator& operator=(const AscendingIterator& other); // Copy assignment operator
                AscendingIterator& operator++(); 

                bool operator==(const AscendingIterator& other) const;
                bool operator!=(const AscendingIterator& other) const;
                bool operator<(const AscendingIterator& other) const;
                bool operator>(const AscendingIterator& other) const;

				int operator*();

                AscendingIterator &begin(); 
                AscendingIterator &end();
        };

        class SideCrossIterator
        {
            private:
                MagicalContainer& container;
                vector<int*>::iterator iter;
                size_t pos;

            public:
                SideCrossIterator(MagicalContainer& container);
                SideCrossIterator(const SideCrossIterator& other);
                ~SideCrossIterator() = default;

                SideCrossIterator& operator=(const SideCrossIterator& other); // Copy assignment operator
                SideCrossIterator& operator++(); 

                bool operator==(const SideCrossIterator& other) const;
                bool operator!=(const SideCrossIterator& other) const;
                bool operator<(const SideCrossIterator& other) const;
                bool operator>(const SideCrossIterator& other) const;

                int& operator*();

                SideCrossIterator &begin(); 
                SideCrossIterator &end();
        };


        class PrimeIterator
        {
            private:
                MagicalContainer& container;
                vector<int*>::iterator iter;
                size_t pos;

            public:
                PrimeIterator(MagicalContainer& container);
                PrimeIterator(const PrimeIterator& other);
                ~PrimeIterator() = default;

                PrimeIterator& operator=(const PrimeIterator& other); // Copy assignment operator
                PrimeIterator& operator++(); 
                
                bool operator==(const PrimeIterator& other) const;
                bool operator!=(const PrimeIterator& other) const;
                bool operator<(const PrimeIterator& other) const;
                bool operator>(const PrimeIterator& other) const;

				int& operator*();

                PrimeIterator &begin(); 
                PrimeIterator &end();
        };
    };
}
