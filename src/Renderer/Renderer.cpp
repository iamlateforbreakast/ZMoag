//
//
//
//
//
#include <fstream.h>

#include <Renderer.h>

GameRenderer::GameRenderer(GameWorld* world) : Object(NULL, "Renderer")
{
   string filename;
   
   // Get the gfx directory list
   filename = appl->getStringOption("GFX_directory") + "/classic.txt";
   load(filename);
}

GameRenderer::~GameRenderer()
{
// Free the GFX Data
}

void GameRenderer::render()
{
// Take the gameworld and convert it to a Pixmap
}

WorldPoint GameRenderer::convertToWorldCoordinates(int x, int y)
{
}

Pixmap* GameRenderer::renderPixmap(string fileName)
{
   Pixmap* returned_pixmap;
   SDL_Surface *test;
   
   returned_pixmap = new Pixmap();
   returned_pixmap->setPixmap(IMG_Load(fileName.c_str()));
   if (!returned_pixmap->getPixmap())
   {
      error("Not able to load picture %s",fileName.c_str());
      exit(1);
   }
   else
   {
      info("Loaded OK\n");
   }
   return returned_pixmap;
}

void GameRenderer::save(const string fileName) const
{
}

void GameRenderer::load(const string filename)
{
   ifstream gfx_file;
   int nb_pixmap_read = 0;
   int line_number = 0;
   int nb_frames = 0;
   int nb_states = 0;
   int total_pixmap_number = 0;
   string pixmap_filename;
   
// Load the GFX Data
   if (!filename.empty())
   {
      gfx_file.open(filename.c_str(),fstream::in);
      if (!gfx_file)
      {
         error("Cannot open %s\n",filename.c_str());
      }
      else
      {
         debug("Reading GFX file %s\n",filename.c_str());
         gfx_file >> total_pixmap_number;
         gfx_data.resize(total_pixmap_number);
         
         while(!gfx_file.eof())
         {
            gfx_file >> pixmap_filename;
            gfx_file >> nb_frames;
            gfx_file >> nb_states;
            nb_pixmap_read ++;
            gfx_data[nb_pixmap_read] = new PixmapArray("./gfx/"+pixmap_filename, nb_frames, nb_states);
         }
      }
   }
   else
   {
      error("Cannot retrieve the GFX filename\n");
   }
   gfx_file.close();
}

void GameRenderer::print() const
{
}
      
