#include "Factory.h"
#include "purge.h"

const char *lists[] = {"Circle", "Square", "Circle", "123", "Circle"};
int main()
{
    vector<Shape*> shapes;
    try {
        for (const char **cp = lists; **cp; ++cp) {
            shapes.push_back(Shape::factory(*cp));
        }
    } catch(Shape::BadShapeCreation &e) {
        cout << e.what() << endl;
        return 1;
    }
    for (int i =0; i<shapes.size(); ++i) {
        shapes[i]->draw();
        shapes[i]->erase();
    }
    cout << "hahh:";
    purge(shapes);
    return 0;
}
