#include "OpenCVHeaders.h"

Position current;
bool inScreen = false;
// Horizontal
bool incomingLeft = false, incomingRight = false;
bool outcomingLeft = false, outcomingRight = false;
// Vertical
bool incomingTop = false, incomingBottom = false;
bool outcomingTop = false, outcomingBottom = false;

MovementDirection::MovementDirection() {}

MovementDirection::MovementDirection(Position initialPosition) {
	current = initialPosition;
	// With a 640 * 480 frame
	ChangePosition(initialPosition);
	if (!inScreen) {
		// Horizontal
		if (current.X < 320 && current.X > 0) {
			cout << "Un nouvel objet est apparu par la gauche." << endl;
			incomingLeft = true;
			incomingRight = false;
			inScreen = true;
		}
		else if (current.X > 320) {
			cout << "Un nouvel objet est apparu par la droite." << endl;
			incomingRight = true;
			incomingRight = false;
			inScreen = true;
		}
		//// Vertical
		//if (current.Y < 240 && current.Y > 0) {
		//	cout << "et par en haut." << endl;
		//	incomingTop = true;
		//	incomingBottom = false;
		//	inScreen = true;
		//}
		//else if (current.Y > 240) {
		//	cout << "et par en bas." << endl;
		//	incomingBottom = true;
		//	incomingTop = false;
		//	inScreen = true;
		//}
	}
	else {
		// Horizontal
		if (current.X < 320 && current.X > 0) {
			outcomingLeft = true;
			outcomingRight = false;
			inScreen = true;
		}
		else if (current.X > 320) {
			outcomingRight = true;
			outcomingLeft = false;
			inScreen = true;
		}
		//// Vertical
		//if (current.Y < 240 && current.Y > 0) {
		//	cout << "et par en haut." << endl;
		//	incomingTop = true;
		//	incomingBottom = false;
		//	inScreen = true;
		//}
		//else if (current.Y > 240) {
		//	cout << "et par en bas." << endl;
		//	incomingBottom = true;
		//	incomingTop = false;
		//	inScreen = true;
		//}
	}
}

void MovementDirection::ChangePosition(Position newPosition)
{
	if (newPosition.X == 0) {
		inScreen = false;
		if (outcomingLeft) {
			cout << "Un objet est disparu vers la gauche." << endl;
			outcomingLeft = false;
			return;
		}
		else if (outcomingRight) {
			cout << "Un objet est disparu vers la droite." << endl;
			outcomingRight = false;
			return;
		}
	}
	else {
		if ((newPosition.X - current.X) > 1 && (newPosition.X - current.X) < 20) {
			current = newPosition;
			return;
		}
	}
	/*if (newPosition.Y == 0) {
		inScreen = false;
		if (outcomingTop) {
			cout << "ET PAR LE HAUT" << endl;
			outcomingTop = false;
			return;
		}
		else if (outcomingBottom) {
			cout << "ET PART LE BAS" << endl;
			outcomingBottom = false;
			return;
		}
	}
	else {
		if ((newPosition.Y - current.Y) > 1 && (newPosition.Y - current.Y) < 20) {
			current = newPosition;
			return;
		}
	}*/
}

