// Room: /d/lingxiao/sleep.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "休息室");
	set("long", @LONG
這是間整潔的廂房，門窗常閉，光線昏暗。房裏別無他物，只有兩
邊放着幾張收拾得舒舒服服的大牀，看着就讓人想睡覺。
LONG );
	set("sleep_room", "1");
	set("no_clean_up", 0); 
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"zoulang1",
	]));
	set("coor/x", -31020);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

