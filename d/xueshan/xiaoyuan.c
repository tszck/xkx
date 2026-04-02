//      xiaoyuan.c 小院

inherit ROOM;

void create()
{
        set("short","小院");
        set("long",@LONG
這裏是雪山寺內的小院，收拾的相當乾淨利索。來來往往的香客和
喇嘛，一邊在暗示着雪山寺香火之盛，一邊也好象在表示喇嘛的口福也
真不壞。因爲北邊就是個廚房。
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "west" : __DIR__"guangchang",
                "north" : __DIR__"chufang",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -69990);
	set("coor/y", -19900);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
