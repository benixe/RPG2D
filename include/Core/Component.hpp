#pragma once

class Component {
public:
	virtual ~Component() = default;
	bool isActive = true;
};