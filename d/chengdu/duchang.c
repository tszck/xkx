// Room: /d/chengdu/duchang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
        set("short", "賭場");
        set("long", @LONG
這裏是一家賭場，一進門，你就會看見遒勁有力的四個大字“願賭
服輸”。聽說有兩個世外高人在這裏開了這個大場子。沒錢的人最好回
家抱娃娃去。
LONG	);
        set("exits", ([
                "west" : __DIR__"beijie2",                              
        ]));
	set("no_clean_up", 0);
        set("coor/x", -8040);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

 
