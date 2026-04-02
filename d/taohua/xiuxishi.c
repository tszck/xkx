// Room: xiuxishi.c

inherit RESTROOM_IN;

void create()
{
        set("short", "桃花軒");
        set("long", @LONG
這是間整潔的廂房，因門窗常閉着，光線很昏暗。房裏別無他物，
只有中間放着一張收拾得舒舒服服的大牀，看着就讓人想睡覺。
LONG );
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("coor/x", 8970);
	set("coor/y", -2990);
	set("coor/z", 0);
  set("door_name","門");
	set("door_dir","east");
	set("force_name","梅超風");
  set("outroom",__DIR__"siguoshi");
	setup();
}
