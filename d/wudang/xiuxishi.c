// Room: xiuxishi.c 休息室
// By Marz

inherit RESTROOM_IN;

void create()
{
        set("short", "休息室");
        set("long", @LONG
這是間整潔的廂房，因門窗常閉着，光線很昏暗。房裏別無他物，
只有中間放着一張收拾得舒舒服服的大牀，看着就讓人想睡覺。
LONG );
        set("no_clean_up", 0);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("coor/x", -2030);
	set("coor/y", -910);
	set("coor/z", 90);
  set("door_name","門");
	set("door_dir","south");
	set("force_name","張松溪");
  set("outroom",__DIR__"donglang2");
	setup();
}
