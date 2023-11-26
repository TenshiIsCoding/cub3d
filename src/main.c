/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:44:11 by azaher            #+#    #+#             */
/*   Updated: 2023/10/30 15:45:56 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_window(void *param)
{
	(void)param;
	exit (0);
}

int	main(int argc, char **argv)
{
	// t_game	game;
	
	parsing(argc, argv);
	/*
	game.map_h = 4;
	game.map_w = 9;
	game.map = ft_split("111111111,1P0000001,100000001,111111111",',');
	game.data.mlx = mlx_init();
	game.data.mlx_win = mlx_new_window(game.data.mlx, game.map_w * DISP_SIZE, game.map_h * DISP_SIZE, "Cub3D");
	mlx_hook(game.data.mlx_win, 17, 0L, close_window, game.data.mlx);
	engine_start(&game, &game.player);
	mlx_loop(game.data.mlx);

	(void)argv;
	*/
	return(0);
}
/*
int	main(int argc, char **argv)
{
	

	void *ptr;
    long long int total_allocated = 0;

    while (1) {
        ptr = malloc(1000000); // Allocating 1 MB
        if (ptr != NULL) {
            total_allocated += 1000000;
        } else {
            printf("Failed to allocate more memory.\n");
            break;
        }
    }

    printf("Total memory allocated: %lld bytes\n", total_allocated);
}
int main(int argc, char **argv)
{
	char *ptr;


	while(1)
	{
		ptr = malloc(100000000000000);
		if (!ptr)
		{
			while(1)
			{
				ptr = malloc(10000000000000);
				if (!ptr)
				{
					while(1)
					{
						ptr = malloc(1000000000000);
						if (!ptr)
						{
							while(1)
							{
								ptr = malloc(100000000000);
								if (!ptr)
								{
									while(1)
									{
										ptr = malloc(10000000000);
										if (!ptr)
										{
											while(1)
											{
												ptr = malloc(1000000000);
												if (!ptr)
												{
													while(1)
													{
														ptr = malloc(100);
														if (!ptr)
														{
															while(1)
															{
																if (!ptr)
																{
																	while(1)
																	{
																		ptr = malloc(10);
																		if (!ptr)
																		{
																			while(1)
																			{
																				ptr = malloc(1);
																				if (!ptr)
																					break;
																			}
																			break;
																		}
																	}
																	break;
																}
															}
															break;
														}
													}
													break;
												}
											}
											break;
										}
									}
									break;
								}
							}
							break;
						}
					}
					break;
				}
			}
			printf("failed to alocate more memory\n");
			break;
		}
	}
	ptr = malloc(11);
	parsing(argc, argv);
	return(0);
}
*/
// int main()
// {
//     void *ptr;
//     long long int total_allocated = 0;

//     while (1) {
//         ptr = malloc(100000000000000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 100000000000000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(10000000000000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 10000000000000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(1000000000000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 1000000000000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(100000000000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 100000000000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(10000000000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 10000000000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(1000000000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 1000000000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(100000000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 100000000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(10000000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 10000000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(1000000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 1000000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(100000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 100000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(10000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 10000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(1000); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 1000;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(100); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 100;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(10); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//             total_allocated += 10;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }
//     while (1) {
//         ptr = malloc(1); // Allocating 1 MB
//         printf("%lli\n", total_allocated);
//         if (ptr != NULL) {
//                 total_allocated += 1;
//         } else {
//             printf("Failed to allocate more memory.\n");
//             break;
//         }
//     }

//     printf("Total memory allocated: %lld bytes\n", total_allocated);
//     char *str = malloc(10000000);
//     str[0] = 'q';
//     str[0] = '0';
//     str[1] = '1';
//     str[2] = '2';
//     str[3] = '3';
//     str[4] = '4';
//     return 0;
// }