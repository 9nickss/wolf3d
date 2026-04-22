/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** wolf3d
*/

#ifndef WOLF3D_H_
    #define WOLF3D_H_

    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <math.h>
    #include <time.h>
    #include <stdbool.h>

    #define M_PI 3.14159265358979323846
    #define MAP_SIZE 50
    #define MINIMAP_SIZE 300
    #define MAX_LINE_LENGTH 10000
    #define TILE_SIZE 64
    #define FOV (M_PI / 3)
    #define SPEED 256.0f
    #define WIN_WIDTH(window) (sfRenderWindow_getSize(window).x)
    #define WIN_HEIGHT(window) (sfRenderWindow_getSize(window).y)
    #define NUM_RAYS(window) WIN_WIDTH(window)
    #define RAY_STEP (TILE_SIZE * 0.1f)
    #define NB_STATE 4
    #define NB_LABEL 4

typedef enum state_s {
    MAIN_SCREEN,
    MAIN_MENU,
    MAIN_LOOP,
    END_GAME
} state_t;

typedef enum label_s {
    NEW_GAME,
    LOAD_GAME,
    SETTINGS,
    QUIT
} label_t;

typedef enum settings_s {
    GAME,
    CONTROLS,
    VIDEO,
    AUDIO
} settings_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    bool on;
} sprite_t;

typedef enum display_mode_e {
    WINDOWED,
    FULLSCREEN,
    WINDOWED_FULLSCREEN
} display_mode_t;

typedef struct settings_page_s {
    sprite_t *all;
    sprite_t *game;
    sprite_t *controle;
    sprite_t *video;
    sprite_t *audio;
    sfRenderWindow *window;
    settings_t current_page;
    sfSound *tab_change_sound;
    sfSoundBuffer *tab_sound_buffer;
    int selected_keybind;
    bool rebinding_active;
    display_mode_t current_display_mode;
    int selected_video_option;
    bool is_selecting_video_mode;
    int current_fps;
    bool is_selecting_fps;
    int selected_fps_option;
    int sensitivity;
    bool is_adjusting_sensitivity;
    int master_volume;
    bool is_adjusting_volume;
    int music_volume;
    bool is_adjusting_music;
    int selected_audio_option;
    sfMusic *background_music;
} settings_page_t;

typedef struct keybinds_s {
    sfKeyCode move_forward;
    sfKeyCode move_backward;
    sfKeyCode move_left;
    sfKeyCode move_right;
    sfKeyCode rotate_left;
    sfKeyCode rotate_right;
} keybinds_t;

typedef struct clocks_s {
    sfClock *main_menu;
    sfClock *main_loop;
    sfClock *end_game;
    sfClock *weapon_anim_clock;
    sfClock *walk_clock;
    sfClock *dash_clock;
} clocks_t;

typedef struct button_s {
    label_t label;
    sfFont *font;
    sfText *text;
    bool on;
} button_t;

typedef struct main_screen_s {
    sprite_t *bg;
    sprite_t *fg;
    sfText *text;
    sfText *title;
    sfFont *font;
} main_screen_t;

typedef struct menu_s {
    button_t *button;
    struct menu_s *prev;
    struct menu_s *next;
} menu_t;

typedef struct main_menu_s {
    sprite_t *menu_screen;
    sprite_t *cursor;
    menu_t *menu;
} main_menu_t;

typedef struct particle_s {
    sfVector2f position;
    sfVector2f velocity;
    float lifetime;
    float max_lifetime;
    float size;
    sfColor color;
    struct particle_s *next;
} particle_t;

typedef struct player_s {
    sfVector2f pos;
    sfVector2f dir;
    float angle;
    float rotation_speed;
    sfRectangleShape *line;
    sfCircleShape *circle;
    sprite_t *weapon;
    bool is_attacking;
    bool is_moving;
    int attack_frame;
    bool can_dash;
    bool is_dashing;
    float fov;
    float base_fov;
    float visual_fov_mult;
    sfVector2f dash_start_pos;
    sfVector2f dash_target_pos;
    float dash_duration;
    bool has_flashlight;
    bool flashlight_on;
    sfCircleShape *flashlight_effect;
    particle_t *particles;
} player_t;

typedef struct prompt_positions_s {
    float rectX;
    float rectY;
    float textX;
    float textY;
} prompt_positions_t;

typedef struct dropdown_positions_s {
    float rectLeft;
    float rectTop;
    float rectWidth;
} dropdown_positions_t;

typedef struct option_style_s {
    const char *text;
    bool isSelected;
} option_style_t;

typedef struct prompt_resources_s {
    sfRectangleShape *promptRect;
    sfText *prompt;
    prompt_positions_t pos;
} prompt_resources_t;

typedef struct prompt_message_pos_s {
    float rectX;
    float rectY;
    float textX;
    float textY;
    float rectWidth;
    float rectHeight;
} prompt_message_pos_t;

typedef struct fps_dropdown_data_s {
    float rectLeft;
    float rectTop;
    float rectWidth;
    const char **options;
} fps_dropdown_data_t;

typedef struct video_option_style_s {
    const char *text;
    bool selected;
    bool active;
    int position;
} video_option_style_t;

typedef struct {
    sfVector2f position;
    int row;
    bool isSelected;
    bool isRebinding;
} keybind_display_t;

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
    sfVector2f basePosition;
} keybind_context_t;

typedef struct keybind_params_s {
    const char *action;
    sfKeyCode key;
    int position;
    sfVector2f startPos;
    bool isSelected;
    bool isRebinding;
} keybind_params_t;

typedef struct hud_s {
    sfTime time_survived;
    sfText *time_txt;
    sfText *time_shadow;
    int score;
    sfText *score_text;
    sfText *score_shadow;
    sprite_t overlay;
    sfRectangleShape *dim_effect;
} hud_t;

typedef struct {
    sfFont *font;
    sfBool is_active;
} tab_style_t;

typedef struct {
    sfVector2f startPos;
    sfVector2f bgPos;
    sfVector2u textureSize;
} controls_ui_layout_t;

typedef struct {
    int position;
    int index;
    sfKeyCode key;
    const char *action;
} keybind_position_t;

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
} render_context_t;

typedef struct {
    float width;
    float height;
} slider_size_t;

typedef struct {
    float pos_x;
    float pos_y;
    float cos_angle;
    float sin_angle;
    float delta_dist_x;
    float delta_dist_y;
} ray_inputs_t;

typedef struct {
    float x;
    float y;
} ray_position_t;

typedef struct {
    int step_x;
    int step_y;
    float side_dist_x;
    float side_dist_y;
} ray_outputs_t;

typedef struct {
    int x;
    int y;
    float side_dist_x;
    float side_dist_y;
} dda_cell_t;

typedef struct {
    int step_x;
    int step_y;
    float delta_dist_x;
    float delta_dist_y;
} dda_step_t;

typedef struct {
    int hit_side;
    int map_x;
    int map_y;
} dda_result_t;

typedef struct {
    float x;
    float width;
    float top;
    float bottom;
} wall_rect_t;

typedef struct {
    int column;
    float column_width;
    float start_angle;
    float ray_angle_step;
} ray_column_params_t;

// <--------------------------INIT_STRUCT------------------------------->

void draw_particles(void);
void update_particles(void);

// init_hud.c
hud_t **get_hud(void);
int init_hud(void);

// hud.c
void handle_hud(void);
void print_score(void);

// init_clock.c
clocks_t **get_clock(void);
int init_clock(void);

// init_floor_ceiling.c
sfVertexArray *get_floor(void);
sfVertexArray *get_ceiling(void);

// init_all_struct.c
int init_all_struct(void);

// init_main_menu.c
main_menu_t **get_main_menu(void);
int fill_main_menu(void);
int init_main_menu(void);

main_screen_t **get_main_screen(void);
int init_main_screen(void);

// init_map.c
int ***get_map(void);
int init_map(void);

// init_player.c
player_t **get_player(void);
int init_player(void);
int init_weapon(void);

// init_state.c
state_t *get_state(void);
int init_state(void);

// init_window.c
sfRenderWindow **get_window(void);
int init_full_screen(void);
int init_window(void);
int init_windowed(void);

// <--------------------------MAIN_SCREEN------------------------------->

// display_main_screen.c
void draw_main_screen(void);

// <---------------------------MAIN_MENU-------------------------------->

// button_main_menu.c
void set_text(sfText **text, sfFont *font,
    const char *text_value, sfVector2f pos);
button_t *add_button(label_t label, const char *text,
    const char *font, sfVector2f pos);
int add_main_menu(label_t label, const char *text,
    const char *font, sfVector2f pos);

// display_main_menu.c
void draw_buttons(button_t *button);
void draw_main_menu(void);

void new_game(void);
void load_game(void);
void settings(void);
void quit(void);

// event_main_menu.c
void arrows_mouse_menu(void);
void arrows_key_menu(void);
void valid_label_mouse(void);
void valid_label_key(void);
void browse_main_menu(menu_t **current);
void change_button_on(button_t **button);
int browse_main_menu_mouse(menu_t **current, menu_t *head, bool state);

// free_main_menu.c
void free_main_menu(void);

// <---------------------------MAINLOOP-------------------------------->

// cast_rays.c
void cast_all_rays(void);

// display_floor_ceiling.c
int is_wall(int x, int y);
void draw_floor_and_ceiling(sfRenderWindow *window);

// display_game.c
void draw_game(void);

// display_minimap.c
void draw_2d_map(void);

// display_player.c
void draw_player(void);
void draw_player_direction(void);

// display_rules.c
int display_rules(void);

// free_gameloop.c
void free_game_resources(void);
void free_hud(void);

// game_event.c
void close_window(sfRenderWindow *window, sfEvent event);
void analyse_events(void);
void full_screen_window(sfRenderWindow *window, sfEvent event);

// gameloop.c
int gameloop(void);

// player_moves.c
void move_player(keybinds_t keybinds);

// set_sprite.c
void set_sprite(bool on, sprite_t *sprite, sfVector2f pos, sfVector2f scale);
sprite_t *get_sprite(const char *path);

// dash_animation.c
void update_dash_animation(void);
void draw_dash_flash(void);
void update_dash_struct(sfVector2f target_pos);
void update_dash_effects(void);
void reset_fov(void);

// update_weapons.c
void update_weapon_pos(void);
void handle_attack_anim(void);
void check_attack_input(void);
void draw_weapon(void);

// From ray_casting_core.c
float calculate_corrected_distance(float wall_dist, float ray_angle);
void calculate_delta_distances(float sin_angle, float cos_angle,
    float *delta_dist_x, float *delta_dist_y);
void setup_step_and_side_dist(ray_inputs_t inputs, ray_outputs_t *outputs);
void setup_ray_parameters(float ray_angle,
    ray_position_t position, ray_outputs_t *outputs);
void perform_dda_step(dda_cell_t *cell,
    dda_step_t step, int *side, float *distance);

// From ray_casting_algorithm.c
void init_dda_params(float ray_angle, ray_position_t position,
    dda_cell_t *cell, dda_step_t *step);
float run_dda_loop(dda_cell_t *cell, dda_step_t step,
    int *side, int *hit_wall);
float perform_dda_algorithm(dda_result_t *result,
    float ray_angle, ray_position_t position);
float cast_single_ray(float ray_angle,
    int *hit_side, int *map_x, int *map_y);
float calculate_wall_x(int side, float ray_angle, float distance);

// From wall_rendering.c
sfColor get_wall_base_color(int hit_side, float ray_angle);
sfColor apply_brightness_and_side_dimming(sfColor base_color,
    float brightness, int hit_side);
sfColor calculate_wall_color(int hit_side,
    float ray_angle, float corrected_dist);
void create_wall_quad(sfVertex *quad, wall_rect_t rect, sfColor wall_color);
wall_rect_t calculate_wall_dimensions(ray_column_params_t params,
    sfRenderWindow *window, int *hit_side);

// From ray_rendering.c
void process_single_ray_column(sfVertexArray *wall_vertices,
    ray_column_params_t params, sfRenderWindow *window);
void cast_all_rays(void);

// <---------------------------SETTINGS-------------------------------->

//display settings

void draw_settings_tabs(void);
void display_settings(void);
void draw_settings_page(void);
sprite_t *get_current_page_sprite(settings_page_t *settings);
void draw_page_sprite(sfRenderWindow *window, sprite_t *current);
void draw_current_page_content(sfRenderWindow *window,
    settings_page_t *settings);

void draw_video_settings(sfRenderWindow *window);
void apply_display_mode(display_mode_t mode);

// video_prompt_message.c functions
prompt_message_pos_t init_message_positions(void);
sfText *create_message_text(sfFont *font, const char *message);
void calculate_message_positions(sfVector2f position, sfFloatRect textBounds,
    prompt_message_pos_t *pos);
sfRectangleShape *create_message_rect(prompt_message_pos_t pos);
void render_message(sfRenderWindow *window, sfText *prompt,
    sfRectangleShape *promptRect, prompt_message_pos_t pos);
void draw_video_dropdown(sfRenderWindow *window, sfFont *font,
    sfVector2f startPos, settings_page_t *settings);
void draw_display_prompt(sfRenderWindow *window,
    sfFont *font, sfVector2f startPos);
void draw_display_arrow(sfRenderWindow *window,
    sfFont *font, sfVector2f position);
void draw_display_checkmark(sfRenderWindow *window,
    sfFont *font, sfVector2f position);
void draw_selection_arrow(sfRenderWindow *window,
    sfFont *font, sfVector2f position);
void draw_checkmark(sfRenderWindow *window,
    sfFont *font, sfVector2f position);
void draw_fps_dropdown(sfRenderWindow *window, sfFont *font,
    sfVector2f position, settings_page_t *settings);
void draw_prompt_message(sfRenderWindow *window,
    sfFont *font, sfVector2f position);


// Video UI helper functions

void draw_helmet_sprite(sfRenderWindow *window, sfSprite *helmetSprite,
    sfVector2f position);
void draw_selection_arrow(sfRenderWindow *window, sfFont *font,
    sfVector2f position);
void draw_checkmark(sfRenderWindow *window, sfFont *font,
    sfVector2f position);
void draw_display_arrow(sfRenderWindow *window, sfFont *font,
    sfVector2f position);
void draw_display_checkmark(sfRenderWindow *window, sfFont *font,
    sfVector2f position);

// From video_prompt.c
prompt_positions_t init_prompt_positions(void);
void calculate_prompt_positions(sfVector2f startPos,
    prompt_positions_t *positions);
sfText *create_prompt_text(sfFont *font,
    const char *message, sfVector2f position);
sfRectangleShape *create_prompt_rect(sfFloatRect textBounds,
    sfVector2f position, float padding_x, float padding_y);

// From video_ui_helpers.c
void draw_display_arrow(sfRenderWindow *window,
    sfFont *font, sfVector2f position);
void draw_display_checkmark(sfRenderWindow *window,
    sfFont *font, sfVector2f position);
void draw_selection_arrow(sfRenderWindow *window,
    sfFont *font, sfVector2f position);
void draw_checkmark(sfRenderWindow *window, sfFont *font, sfVector2f position);

// From video_dropdown.c
void draw_video_dropdown(sfRenderWindow *window, sfFont *font,
    sfVector2f startPos, settings_page_t *settings);

// From video_fps_dropdown.c
void draw_fps_dropdown(sfRenderWindow *window, sfFont *font,
    sfVector2f position, settings_page_t *settings);

// From video_prompt_message.c
void draw_prompt_message(sfRenderWindow *window,
    sfFont *font, sfVector2f position);
prompt_message_pos_t init_message_positions(void);
sfText *create_message_text(sfFont *font, const char *message);
void calculate_message_positions(sfVector2f position, sfFloatRect textBounds,
    prompt_message_pos_t *pos);
sfRectangleShape *create_message_rect(prompt_message_pos_t pos);
void render_message(sfRenderWindow *window, sfText *prompt,
    sfRectangleShape *promptRect, prompt_message_pos_t pos);
void draw_video_header(sfRenderWindow *window, sfFont *font,
    sfVector2f bgPos, sfVector2u textureSize);
void draw_display_mode_section(sfRenderWindow *window, sfFont *font,
    sfVector2f startPos, sfSprite *helmetSprite);
void draw_fps_section(sfRenderWindow *window, sfFont *font,
    sfVector2f fpsPosition, sfSprite *helmetSprite);
void setup_video_resources(settings_page_t **settings, sfFont **font,
    sfSprite **helmetSprite, sfTexture **helmetTexture);
void cleanup_video_resources(sfSprite *helmetSprite, sfTexture *helmetTexture,
    sfFont *font);


//fps

void draw_video_settings(sfRenderWindow *window);
void draw_fps_option(sfRenderWindow *window, sfFont *font, sfVector2f position,
    settings_page_t *settings);
void apply_display_mode(display_mode_t mode);
void apply_fps_setting(int fps);

//sensitivity

void draw_game_settings(sfRenderWindow *window);
void apply_sensitivity_setting(int sensitivity);
void draw_sensitivity_control(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f position);
void apply_sensitivity_setting(int sensitivity);

//audio

void draw_audio_settings(sfRenderWindow *window);
void apply_volume_setting(int volume);
void apply_music_volume(int volume);
void play_background_music(void);
void stop_background_music(void);
void draw_master_volume_label(sfRenderWindow *window, sfFont *font);
void draw_volume_slider_background(sfRenderWindow *window,
    sfVector2f position, float width, float height);
void draw_volume_slider_fill(sfRenderWindow *window,
    sfVector2f position, slider_size_t size, float fillRatio);
void draw_master_volume_value(sfRenderWindow *window, sfFont *font,
    sfVector2f position, int volume);
void draw_volume_adjustment_arrows(sfRenderWindow *window, sfFont *font,
    sfVector2f position, sfBool isAdjusting);
void draw_volume_instructions(sfRenderWindow *window, sfFont *font,
    sfVector2f position);
void draw_music_label(sfRenderWindow *window,
    sfFont *font, sfVector2f position);
void draw_slider_background(sfRenderWindow *window, sfVector2f position,
    float width, float height);
void draw_slider_fill(sfRenderWindow *window, sfVector2f position,
    slider_size_t size, float fillRatio);
void draw_volume_text(sfRenderWindow *window, sfFont *font,
    sfVector2f position, int volume);
void draw_adjustment_arrows(sfRenderWindow *window, sfFont *font,
    sfVector2f position, sfBool isAdjusting);
void draw_volume_control(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f position);
void draw_music_control(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f position);

// Prototypes for settings input handlers
bool handle_rebinding(settings_page_t *settings, keybinds_t *keybinds,
    settings_t page, sfEvent event);
void handle_game_settings(settings_page_t *settings, sfEvent event);
void handle_sensitivity_adjustment(settings_page_t *settings, sfEvent event);
void handle_controls_settings(settings_page_t *settings, sfEvent event);
void handle_controls_up_navigation(settings_page_t *settings);
void handle_controls_down_navigation(settings_page_t *settings);
void handle_video_settings(settings_page_t *settings, sfEvent event);
void handle_video_mode_selection(settings_page_t *settings, sfEvent event);
void apply_video_mode(settings_page_t *settings);
void handle_fps_selection(settings_page_t *settings, sfEvent event);
void apply_fps_option(settings_page_t *settings);
void handle_video_navigation(settings_page_t *settings, sfEvent event);
void handle_video_enter(settings_page_t *settings);
void handle_video_down(settings_page_t *settings);
void handle_video_up(settings_page_t *settings);
void handle_audio_settings(settings_page_t *settings, sfEvent event);
void handle_master_volume(settings_page_t *settings, sfEvent event);
void handle_music_volume(settings_page_t *settings, sfEvent event);
void handle_audio_navigation(settings_page_t *settings, sfEvent event);
void handle_audio_enter(settings_page_t *settings);
void decrease_master_volume(settings_page_t *settings);
void increase_master_volume(settings_page_t *settings);
void decrease_music_volume(settings_page_t *settings);
void increase_music_volume(settings_page_t *settings);
void decrease_sensitivity(settings_page_t *settings);
void increase_sensitivity(settings_page_t *settings);

// Settings event core functions
void handle_event_by_type(settings_page_t *settings, sfEvent event);
void handle_key_press(settings_page_t *settings, sfEvent event);
void process_event(settings_page_t *settings, sfEvent event);
void settings_event(void);
void route_settings_by_page(settings_page_t *settings,
    settings_t page, sfEvent event);

// Settings navigation
bool should_handle_special_navigation(settings_page_t *settings);
void handle_left_right_keys(settings_page_t *settings, sfEvent event);
void handle_up_down_keys(settings_page_t *settings, sfEvent event);
void handle_settings_input(settings_t page, sfEvent event);
void handle_escape_key(settings_page_t *settings);
void change_settings_page(settings_t *current_page, int direction);
bool *get_in_settings(void);

// Controls settings
bool handle_rebinding(settings_page_t *settings, keybinds_t *keybinds,
    settings_t page, sfEvent event);
void handle_controls_up_navigation(settings_page_t *settings);
void handle_controls_down_navigation(settings_page_t *settings);
void handle_controls_enter(settings_page_t *settings);
void handle_controls_settings(settings_page_t *settings, sfEvent event);
void apply_rebinding(int selected_keybind,
    keybinds_t *keybinds, sfEvent event);
void draw_keybind(sfRenderWindow *window, sfFont *font,
    keybind_params_t params);
void configure_keybind_params(keybind_params_t *params,
    settings_page_t *settings, keybind_position_t pos_info);
void draw_all_keybinds(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f startPos);
void draw_rotation_keybinds(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f startPos);

// Game settings
void handle_game_settings(settings_page_t *settings, sfEvent event);
void handle_sensitivity_adjustment(settings_page_t *settings, sfEvent event);
void handle_sensitivity_exit(settings_page_t *settings);
void decrease_sensitivity(settings_page_t *settings);
void increase_sensitivity(settings_page_t *settings);
void apply_sensitivity_setting(int sensitivity);

// Video settings
void handle_video_settings(settings_page_t *settings, sfEvent event);
void handle_video_navigation(settings_page_t *settings, sfEvent event);
void handle_video_default_selection(settings_page_t *settings);
void handle_video_enter(settings_page_t *settings);
void handle_video_up(settings_page_t *settings);
void handle_video_down(settings_page_t *settings);

// Video mode settings
void handle_video_mode_selection(settings_page_t *settings, sfEvent event);
void handle_video_mode_up(settings_page_t *settings);
void handle_video_mode_down(settings_page_t *settings);
void handle_video_mode_escape(settings_page_t *settings);
void apply_video_mode(settings_page_t *settings);
void apply_display_mode(display_mode_t mode);

// FPS settings
void handle_fps_selection(settings_page_t *settings, sfEvent event);
void handle_fps_up(settings_page_t *settings);
void handle_fps_down(settings_page_t *settings);
void handle_fps_escape(settings_page_t *settings);
void apply_fps_option(settings_page_t *settings);
void apply_fps_setting(int fps);

// Audio settings
void handle_audio_settings(settings_page_t *settings, sfEvent event);
void handle_audio_navigation(settings_page_t *settings, sfEvent event);
void handle_audio_down(settings_page_t *settings);
void handle_audio_up(settings_page_t *settings);
void handle_audio_enter(settings_page_t *settings);

// Volume settings
void handle_master_volume(settings_page_t *settings, sfEvent event);
void handle_master_exit(settings_page_t *settings);
void handle_master_volume_down(settings_page_t *settings);
void decrease_master_volume(settings_page_t *settings);
void increase_master_volume(settings_page_t *settings);
void apply_volume_setting(int volume);

// Music settings
void handle_music_volume(settings_page_t *settings, sfEvent event);
void handle_music_exit(settings_page_t *settings);
void handle_music_volume_up(settings_page_t *settings);
void decrease_music_volume(settings_page_t *settings);
void increase_music_volume(settings_page_t *settings);
void apply_music_volume(int volume);
void play_background_music(void);
void stop_background_music(void);

// Settings access
settings_page_t **get_settings_page(void);
keybinds_t *get_keybinds(void);
void free_settings_resources(void);

// Initialization functions
int init_settings(void);
int init_keybinds(void);

// UI Drawing functions
void draw_controls_settings(sfRenderWindow *window);
void display_settings(void);
void toggle_flashlight(void);
void draw_flashlight(void);
void move_player(keybinds_t keybinds);
void move_forward(void);
void move_backward(void);
void move_left(void);
void move_right(void);
void left_rotation(void);
void right_rotation(void);
void dash(void);
void toggle_flashlight(void);

#endif /* WOLF3D_H_ */
