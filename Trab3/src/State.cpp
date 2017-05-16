#include "../include/State.hpp"

State::State(std::string tsFile, std::string tmName) :
    varQuitRequested(false),
    bg("img/ocean.jpg"),
    tileSet(64,64,tsFile),
    tileMap(tmName, &tileSet){
    // tileSet = *(new TileSet(64,64,tsFile));
    // tileMap = *(new TileMap(tmName, &tileSet));
}

bool State::quitRequested() const{
	return varQuitRequested;
}

void State::requestQuit(){
	varQuitRequested = true;
}

void State::loadAssets(){

}

void State::update(double dt){
	input();

	for(int i = 0; i < (int)objectArray.size(); i++){
		if(objectArray[i]->isDead())
			objectArray.erase(objectArray.begin() + i);
	}
}

void State::render(){
	tileMap.render(0,0);

	for(int i = 0; i < (int)objectArray.size(); i++){
		objectArray[i]->render();
	}
}

State::~State(){
	objectArray.clear();
}

void State::input() {
    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (varQuitRequested == false && SDL_PollEvent(&event)) {

        // Se o evento for quit, setar a flag para terminação
        if(event.type == SDL_QUIT) {
            varQuitRequested = true;
        }
        
        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for(int i = (int)objectArray.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face.
                Face* face = (Face*) objectArray[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.

                if(face->box.isInside((float)mouseX, (float)mouseY)) {
                    // Aplica dano
                    face->damage(rand() % 10 + 10);
                    // Sai do loop (só queremos acertar um)
                    break;
                }
            }
        }
        if( event.type == SDL_KEYDOWN ) {
            // Se a tecla for ESC, setar a flag de quit
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
                varQuitRequested = true;
            }
            // Se não, crie um objeto
            else {
                addObject((float)mouseX, (float)mouseY);
            }
        }
    }
}

void State::addObject(float mouseX, float mouseY){
	double ang = rand()%360*acos(-1)/180;
	float newX = cos(ang)*200 + mouseX;
	float newY = sin(ang)*200 + mouseY;
	objectArray.emplace_back(new Face(newX, newY));
}