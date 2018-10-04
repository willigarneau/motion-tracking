#include "OpenCVHeaders.h"

Position current;
bool inScreen = false;
bool incomingLeft = false, incomingRight = false;
bool outcomingLeft = false, outcomingRight = false;

MovementDirection::MovementDirection() {}

MovementDirection::MovementDirection(Position initialPosition) {
	current = initialPosition;
	bool change = false;
	// With a 640 * 480 frame
	ChangePosition(initialPosition);
	if (!inScreen) {
		if (current.X < 60 && current.X > 0) {
			cout << "Un nouvel objet est apparu par la gauche." << endl;
			incomingLeft = true;
			incomingRight = false;
			inScreen = true;
		}
		else if (current.X > 600) {
			cout << "Un nouvel objet est apparu par la droite." << endl;
			incomingRight = true;
			incomingRight = false;
			inScreen = true;
		}
	}
	else {
		if (current.X < 60 && current.X > 0) {
			outcomingLeft = true;
			outcomingRight = false;
			inScreen = true;
		}
		else if (current.X > 600) {
			outcomingRight = true;
			outcomingLeft = false;
			inScreen = true;
		}
	}
}

void MovementDirection::ChangePosition(Position newPosition)
{
	if (newPosition.X == 0) {
		inScreen = false;
	}
	else {
		if ((newPosition.X - current.X) > 1 && (newPosition.X - current.X) < 20) {
			current = newPosition;
			return;
		}
	}
}

