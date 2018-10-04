#include "OpenCVHeaders.h"

Position current;
bool inScreen = false;

MovementDirection::MovementDirection() {}

MovementDirection::MovementDirection(Position initialPosition) {
	current = initialPosition;
	bool change = false;
	// With a 640 * 480 frame
	if (current.X < 60 && !inScreen) {
		change = ChangePosition(initialPosition);
		if (!inScreen) cout << "Un nouvel objet est apparu par la gauche." << endl;
		inScreen = true;
	}
	else if (current.X > 600 && !inScreen) {
		change = ChangePosition(initialPosition);
		if (!inScreen) cout << "Un nouvel objet est apparu par la droite." << endl;
		inScreen = true;
	}
}

bool MovementDirection::ChangePosition(Position newPosition)
{
	if ((newPosition.X - current.X) > 1 && (newPosition.X - current.X) < 20) {
		current = newPosition;
		return true;
	}
	inScreen = false;
}

