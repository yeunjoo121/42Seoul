#include "./so_long.h"
#include "./mlx/mlx.h"

void gui_window()
{
    void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	mlx_loop(mlx);
}