#pragma once
#include <vector>

using namespace std;

namespace ariel
{
	class MagicalContainer
	{
		private:
			vector<int> elements;
		public:
			MagicalContainer();
			void addElement(int element);
			void removeElement(int element);
			
			size_t size() const;

			class AscendingIterator
			{
				private:
					MagicalContainer &container;
					size_t currentIndex;
					AscendingIterator(MagicalContainer &container, size_t index);
				
                public:
					AscendingIterator(MagicalContainer &cont);
					AscendingIterator(const AscendingIterator &other);
                    AscendingIterator(AscendingIterator &&other) noexcept;

                    ~AscendingIterator() = default;

					bool operator==(const AscendingIterator &other) const;
					bool operator!=(const AscendingIterator &other) const;
					bool operator<(const AscendingIterator &other) const;
					bool operator>(const AscendingIterator &other) const;
					int operator*() const;

					AscendingIterator &operator=(const AscendingIterator &other);
					AscendingIterator &operator=(AscendingIterator &&other) noexcept;
					AscendingIterator &operator++();

					AscendingIterator begin();
					AscendingIterator end() const;
			};

			class SideCrossIterator
			{
				private:
					MagicalContainer &container;
					size_t currentIndex;
					SideCrossIterator(MagicalContainer &container, size_t index);
				
                public:
					SideCrossIterator(MagicalContainer &cont);
					SideCrossIterator(const SideCrossIterator &other);
					SideCrossIterator(SideCrossIterator &&other) noexcept;

					~SideCrossIterator() = default;

					bool operator==(const SideCrossIterator &other) const;
					bool operator!=(const SideCrossIterator &other) const;
					bool operator<(const SideCrossIterator &other) const;
					bool operator>(const SideCrossIterator &other) const;
					int operator*() const;
					
                    SideCrossIterator &operator=(const SideCrossIterator &other);
					SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;
					SideCrossIterator &operator++();
					SideCrossIterator begin();
					SideCrossIterator end() const;
			};

			class PrimeIterator
			{
				private:
					MagicalContainer &container;
					size_t currentIndex;
					PrimeIterator(MagicalContainer &container, size_t index);

				public:

					PrimeIterator(MagicalContainer &cont);
					PrimeIterator(const PrimeIterator &other);
					PrimeIterator(PrimeIterator &&other) noexcept;

                    ~PrimeIterator() = default;

					bool operator==(const PrimeIterator &other) const;
					bool operator!=(const PrimeIterator &other) const;
					bool operator<(const PrimeIterator &other) const;
					bool operator>(const PrimeIterator &other) const;
					int operator*() const;

                    PrimeIterator &operator=(const PrimeIterator &other);
					PrimeIterator &operator=(PrimeIterator &&other) noexcept;
					PrimeIterator &operator++();
                    
					PrimeIterator begin();
					PrimeIterator end() const;
			};
	};
}