/*
** EPITECH PROJECT, 2022
** flag
** File description:
** flag
*/

#include "../inc/tetris.h"

void default_flags (flags *f)
{
    f->level = 1;
    f->left = KEY_LEFT;
    f->right = KEY_RIGHT;
    f->turn = KEY_UP;
    f->drop = KEY_DOWN;
    f->quit = 'q';
    f->pause = ' ';
    f->size.x = 10;
    f->size.y = 20;
    f->next = 1;
    f->debug = 0;
    f->pause_id = 1;
}

void read_help (char *bin)
{
    my_putstr("Usage: ");
    my_putstr(bin);
    int fd = open("HELP", O_RDONLY);
    char i[333];
    int size = 10;
    while (size == 10) {
        size = read(fd, i, 10);
        write(1, i, size);
    }
    close(fd);
    exit(0);
}

void set_flag (flags *f, char opt, char *val, char *bin)
{
    int error = 0, i = 0;
    set_flag3(opt, bin);
    if (val == NULL) {
        (opt == 'w') ? f->next = 0 : 0;
        (opt == 'D') ? f->debug = 1 : 0;
        return;
    }
    char *tmp = (val[0] == '-') ? &val[1] : val, *a = val, *b = NULL;
    if (opt == 'S') {
        for (int i = 0;val[i] != '\0';(val[i] == ',') ? error++ : 0, i++);
        if (error != 1) exit(84);
    } else
        for (int i = 0; tmp[i] != '\0'; i++)
            (char_is_num(tmp[i]) == 0) ? exit(84) : 0;
    set_flag2(f, opt, val);
    for (i = 0;val[i] != ',' && val[i] != '\0';i++, b = &a[i]);
    a[i] = '\0';
    b++;
    (opt == 'S') ? f->size.x = my_getnbr(b) : 0;
    (opt == 'S') ? f->size.y = my_getnbr(a) : 0;
}

flags *setup_flags (int argc, char **argv)
{
    flags *f = malloc(sizeof(flags));
    default_flags(f);
    int opt, oi = 0;
    char *flag_list = "LlrtdqpSwDh";
    static struct option lo[] = {
        {"level", 1, 0, 0},
        {"key-left", 1, 0, 0}, {"key-right", 1, 0, 0}, {"key-turn", 1, 0, 0},
        {"key-drop", 1, 0, 0}, {"key-quit", 1, 0, 0}, {"key-pause", 1, 0, 0},
        {"map-size", 1, 0, 0}, {"without-next", 0, 0, 0},
        {"debug", 0, 0, 0}, {"help", 0, 0, 0}, {0, 0, 0, 0}};
    while (1) {
        opt = getopt_long(argc, argv, ":L:l:r:t:d:q:p:wD", lo, &oi);
        if (opt == -1) break;
        if (opt == 0) {
            set_flag(f, flag_list[oi], optarg, argv[0]);
        } else
            set_flag(f, opt, optarg, argv[0]);
    }
    return f;
}
