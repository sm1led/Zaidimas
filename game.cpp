#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_p, player_dp;
float arena_half_size_x = 85, arena_half_size_y = 45;
float player_half_size_x = 2.5, player_half_size_y = 12;
float ball_p_x, ball_p_y, ball_dp_x = 100, ball_dp_y, ball_half_size = 1;

internal void
simulate_game(Input *input, float dt)
{
	clear_screen(0xff5500);
	draw_rect(0, 0, arena_half_size_x, arena_half_size_y, 0xffaa33);
	float player_ddp = 0.f; // units per second
	if (is_down(BUTTON_UP)) player_ddp += 2000;
	if (is_down(BUTTON_DOWN)) player_ddp -= 2000;

	player_ddp -= player_dp * 10.f;

	player_p = player_p + player_dp * dt + player_ddp * dt * dt * .5f;
	player_dp = player_dp + player_ddp * dt;

	if (player_p + player_half_size_y > arena_half_size_y)
	{
		player_p = arena_half_size_y - player_half_size_y;
		player_dp *= -1;
	}
	if (player_p - player_half_size_y < -arena_half_size_y)
	{
		player_p = -arena_half_size_y + player_half_size_y;
		player_dp *= -1;
	}

	ball_p_x += ball_dp_x * dt;
	ball_p_y += ball_dp_y * dt;

	draw_rect(ball_p_x, ball_p_y, 1, 1, 0xffffff);

	draw_rect(-80, player_p, player_half_size_x, player_half_size_y, 0xff0000);
	draw_rect(80, 0, 2.5, 12, 0xff0000);
}