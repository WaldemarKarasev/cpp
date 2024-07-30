#include <algorithm>
#include <iostream>
#include <vector>

namespace TsurugiNoMai {

    class BaseRenderSystem 
    {
    public:
        virtual void render() = 0;
    };

    class RenderPlaneSystem : public BaseRenderSystem
    {
    public:
        virtual void render() override { std::cout << "Plane rendered!" << std::endl; }
    };

    class RenderCarSystem : public BaseRenderSystem
    {
    public:
        virtual void render() override { std::cout << "Car rendered!" << std::endl; }
    };


    class BaseRenderBackend
    {
    public:
        virtual void RenderSystems() = 0;
    };

  
    class CarRenderBackend : public BaseRenderBackend
    {
    public: 
        virtual void RenderSystems() override { 
            if (m_CarSystems_.empty())
            {
                std::cout << "Plane Systems are empty" << std::endl;
                return;
            }
            std::for_each(m_CarSystems_.begin(), m_CarSystems_.end(), [](RenderCarSystem* system){
                system->render();
            });
        }
    
    //private:
        std::vector<RenderCarSystem*> m_CarSystems_;
    };
   
    class PlaneRenderBackend : public BaseRenderBackend
    {
    public:
        virtual void RenderSystems() override {
            if ( m_PlaneSystems_.empty())
            {
                std::cout << "Plane Systems are empty" << std::endl;
                return;
            }
            std::for_each(m_PlaneSystems_.begin(), m_PlaneSystems_.end(), [](RenderPlaneSystem* system){
                system->render();
            });               
        }

    //private:
        std::vector<RenderPlaneSystem*> m_PlaneSystems_;
    };

}

int main()
{
    TsurugiNoMai::BaseRenderBackend* CarBack = new TsurugiNoMai::CarRenderBackend();
    TsurugiNoMai::BaseRenderBackend* PlaneBack = new TsurugiNoMai::PlaneRenderBackend();

    TsurugiNoMai::BaseRenderSystem* CarSystem = new TsurugiNoMai::RenderCarSystem();
    TsurugiNoMai::BaseRenderSystem* PlaneSystem = new TsurugiNoMai::RenderPlaneSystem();

    dynamic_cast<TsurugiNoMai::PlaneRenderBackend*>(PlaneBack)->m_PlaneSystems_.push_back(dynamic_cast<TsurugiNoMai::RenderPlaneSystem*>(PlaneSystem));

    PlaneBack->RenderSystems();
}