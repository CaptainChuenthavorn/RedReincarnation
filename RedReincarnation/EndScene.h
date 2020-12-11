#include <sfml\Graphics.hpp>
#define MAX_ITEMS 2 //Menu 
class EndScene
{
public:
	EndScene(float width, float height);
	~EndScene();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItem; }

private:
	int selectedItem = 0;
	sf::Font font;
	sf::Text Endmenu[MAX_ITEMS];
};