struct Position {
	int X;
	int Y;
};

#pragma once
class MovementDirection
{
public:
	MovementDirection();
	void ChangePosition(Position newPosition);
};

