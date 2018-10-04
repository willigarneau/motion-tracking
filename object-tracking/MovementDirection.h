struct Position {
	int X;
	int Y;
};

#pragma once
class MovementDirection
{
public:
	MovementDirection();
	MovementDirection(Position initialPosition);
	bool ChangePosition(Position newPosition);
};

