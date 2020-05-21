internal void
simulate_game(Input *input)
{
	clear_screen(0xff5500);
	if (input->buttons[BUTTON_UP].is_down)
		draw_rect(0, 0, 20, 20, 0x00ff22);
}