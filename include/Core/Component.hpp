#pragma once

class Component {

public:
	virtual ~Component() = default;
	bool isActive = true;
};

class Transform {

public:
	int x;
	int y;
};

class