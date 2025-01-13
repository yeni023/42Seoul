#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char** av) {
    for (int i = 1; i < ac; i++) {
        std::string data = av[i];
        if (!isNumber(data))
            throw std::logic_error("Error: not a number: " + data);

        long long num = std::atol(av[i]);
        if (num > 2147483647 || num < -2147483648)
            throw std::logic_error("Error: number out of int range: " + data);

        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
}

PmergeMe::PmergeMe(const PmergeMe& rhs) { *this = rhs; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if (this != &rhs) {
		vec = rhs.vec;
		deq = rhs.deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isNumber(const std::string& num) const {
    for (size_t i = 0; i < num.size(); i++)
        if (!isdigit(num[i]))
            return (false);
    return (true);
}

// 야콥스탈 수 계산
size_t PmergeMe::jacobsthalNum(size_t n) {
    return ((pow(2, n) - pow(-1, n)) / 3);
}

/* vector */
void PmergeMe::vectorData() {
	if (vec.size() == 1)
		return ;

	int mergeSize = vec.size() / 2;
	// 초기화 -1, -1으로 초기값 설정
	Pair odd = std::make_pair(-1, -1);

	// 홀수면 마지막 수를 odd에 삽입
	if (vec.size() % 2 == 1)
		odd = std::make_pair(vec[vec.size() - 1], -1);

	std::vector<Pair> topArr;
	std::vector<Pair> bottomArr;
	int i = 0;
	int idx = 0;

    // 상위 및 하위 벡터 생성
	// 작은 값은 topArr, 큰 값은 bottomArr
	while (mergeSize--) {
		topArr.push_back(std::make_pair(vec[i + !(vec[i] > vec[i + 1])], idx++));
		bottomArr.push_back(std::make_pair(vec[i + (vec[i] > vec[i + 1])], -1));
		i += 2;
	}
	// 상위 벡터를 재귀적으로 병합 정렬
	mergeVec(topArr, 1);
	// 하위 벡터의 요소들을 상위 벡터에 삽입
	insertVec(topArr, bottomArr, 0);

	// 홀수인 경우 마지막 요소 삽입
	if (odd.first != -1)
		insertVecOdd(topArr, odd);

	// vec에 정렬된 숫자 저장
	for (size_t j = 0; j < topArr.size(); j++)
		vec[j] = topArr[j].first;
}

void PmergeMe::mergeVec(std::vector<Pair>& before, int iter) {
    if (before.size() == 1)
        return;

    int merge_size = before.size() / 2;
    Pair odd = std::make_pair(-1, -1);

    if (before.size() % 2 == 1)
        odd = before[before.size() - 1];

    std::vector<Pair> topArr;
    std::vector<Pair> bottomArr;
    int i = 0;
    while (merge_size--) {
        topArr.push_back(before[i + !(before[i].first > before[i + 1].first)]);
        bottomArr.push_back(before[i + (before[i].first > before[i + 1].first)]);
        i += 2;
    }

    mergeVec(topArr, iter + 1);
    insertVec(topArr, bottomArr, iter);

    if (odd.first > -1)
        insertVecOdd(topArr, odd);

    before = topArr;
}

void PmergeMe::insertVec(std::vector<Pair>& topArr, std::vector<Pair>& bottomArr, int iter) { // iter == depth
	std::vector<Pair> sorted_arr = topArr;
	// 야콥스탈 수 1은 맨 앞이기 때문에 바로 삽입
	sorted_arr.insert(sorted_arr.begin(), bottomArr[topArr[0].second/static_cast<int>(pow(2, iter))]);
	size_t insert_cnt = 1; // 배열에 넣은 숫자 개수
	std::vector<size_t> jacobsthalArr;
	// 야콥스탈 수 배열 생성
	for (size_t i = 1; jacobsthalNum(i) < topArr.size(); i++)
	// i + 1 삽입 이유 : 야콥 스탈 수가 0 1 1 3 5 .. 인데 2번째 1부터 삽입하기 위하여
		jacobsthalArr.push_back(jacobsthalNum(i + 1));
	// 야콥스탈 수 1은 위에서 바로 sorted_arr에 넣었기 때문에 j = 1부터 시작
	for (size_t j = 1; j < jacobsthalArr.size(); j++) {
		for (size_t jacob_num = jacobsthalArr[j]; jacob_num > jacobsthalArr[j - 1]; jacob_num--) {
			if (jacob_num > topArr.size()) jacob_num = topArr.size();
			Pair value = bottomArr[topArr[jacob_num - 1].second/static_cast<int>(pow(2, iter))];
			sorted_arr = binarySearchVec(sorted_arr, 0, jacob_num + insert_cnt - 2, value);
			insert_cnt++;
		}
	}
	topArr = sorted_arr;
}

std::vector<PmergeMe::Pair> PmergeMe::binarySearchVec(std::vector<Pair> arr, int start, int end, Pair value) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid].first > value.first)
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (arr[start].first > value.first)
		arr.insert(arr.begin() + start, value);
	else
		arr.insert(arr.begin() + start + 1, value);
	return (arr);
}

void PmergeMe::insertVecOdd(std::vector<Pair>& topArr, Pair& odd) {
	int start = 0;
	int end = topArr.size() - 1;
	while (start < end) {
		int mid = (start + end) / 2;
		if (topArr[mid].first > odd.first)
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (topArr[start].first > odd.first)
		topArr.insert(topArr.begin() + start, odd);
	else
		topArr.insert(topArr.begin() + start + 1, odd);
}

void PmergeMe::printArr(int state) {
	if (state == BEFORE_SORT)
		std::cout << "Before: ";
	else if (state == AFTER_SORT)
		std::cout << "After: ";

	for (size_t i = 0; i < vec.size() - 1; i++)
		std::cout << vec[i] << " ";
	std::cout << vec[vec.size() - 1] << std::endl;
}

/* deque */
void PmergeMe::dequeData() {
	if (deq.size() == 1)
		return ;

	int mergeSize = deq.size() / 2;
	Pair odd = std::make_pair(-1, -1);

	if (deq.size() % 2 == 1)
		odd = std::make_pair(deq[deq.size() - 1], -1);

	std::deque<Pair> topArr;
	std::deque<Pair> bottomArr;
	int i = 0;
	int idx = 0;

	while (mergeSize--) {
		topArr.push_back(std::make_pair(deq[i + !(deq[i] > deq[i + 1])], idx++));
		bottomArr.push_back(std::make_pair(deq[i + (deq[i] > deq[i + 1])], -1));
		i += 2;
	}
	mergeDeq(topArr, 1);
	insertDeq(topArr, bottomArr, 0);

	if (odd.first != -1)
		insertDeqOdd(topArr, odd);

	for (size_t j = 0; j < topArr.size(); j++)
		deq[j] = topArr[j].first;
}

void PmergeMe::mergeDeq(std::deque<Pair>& before, int iter) {
    if (before.size() == 1)
        return;

    int merge_size = before.size() / 2;
    Pair odd = std::make_pair(-1, -1);

    if (before.size() % 2 == 1)
        odd = before[before.size() - 1];

    std::deque<Pair> topArr;
    std::deque<Pair> bottomArr;

    int i = 0;
    while (merge_size--) {
        topArr.push_back(before[i + !(before[i].first > before[i + 1].first)]);
        bottomArr.push_back(before[i + (before[i].first > before[i + 1].first)]);
        i += 2;
    }
    mergeDeq(topArr, iter + 1);
    insertDeq(topArr, bottomArr, iter);

    if (odd.first > -1)
        insertDeqOdd(topArr, odd);
    before = topArr;
}

void PmergeMe::insertDeq(std::deque<Pair>& topArr, std::deque<Pair>& bottomArr, int iter) {
	std::deque<Pair> sorted_arr = topArr;
	sorted_arr.insert(sorted_arr.begin(), bottomArr[topArr[0].second/static_cast<int>(pow(2, iter))]);
	size_t insert_cnt = 1;
	std::deque<size_t> jacobsthalArr;
	for (size_t i = 1; jacobsthalNum(i) < topArr.size(); i++)
		jacobsthalArr.push_back(jacobsthalNum(i + 1));

	for (size_t j = 1; j < jacobsthalArr.size(); j++) {
		for (size_t jacob_num = jacobsthalArr[j]; jacob_num > jacobsthalArr[j - 1]; jacob_num--) {
			if (jacob_num > topArr.size())
				jacob_num = topArr.size();

			Pair value = bottomArr[topArr[jacob_num - 1].second/static_cast<int>(pow(2, iter))];
			sorted_arr = binarySearchDeq(sorted_arr, 0, jacob_num + insert_cnt - 2, value);
			insert_cnt++;
		}
	}
	topArr = sorted_arr;
}

std::deque<PmergeMe::Pair> PmergeMe::binarySearchDeq(std::deque<Pair> arr, int start, int end, Pair value) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid].first > value.first)
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (arr[start].first > value.first)
		arr.insert(arr.begin() + start, value);
	else
		arr.insert(arr.begin() + start + 1, value);
	return (arr);
}

void PmergeMe::insertDeqOdd(std::deque<Pair>& topArr, Pair& odd) {
	int st = 0;
	int en = topArr.size() - 1;
	while (st < en) {
		int mid = (st + en) / 2;
		if (topArr[mid].first > odd.first)
			en = mid - 1;
		else
			st = mid + 1;
	}
	if (topArr[st].first > odd.first)
		topArr.insert(topArr.begin() + st, odd);
	else
		topArr.insert(topArr.begin() + st + 1, odd);
}