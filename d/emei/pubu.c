inherit ROOM;
int do_zuan();
void create()
{
        set("short", "瀑布");
        set("long", @LONG
逆着小溪向前走，隨着水聲越來越大，眼前出現了一
個大瀑布，水從上百米高的懸崖上直瀉而下，濺起漫天的
水花，再加上水氣，整個天空都是灰濛濛的。瀑布後面隱
隱有一個山洞。
LONG
        );
        set("exits", ([
            "south" : __DIR__"yhchkou",
        ]));
        set("shorth", "瀑布");
	set("coor/x", -6200);
	set("coor/y", -1160);
	set("coor/z", 200);
	setup();
}
void init()
{
  add_action("do_zuan","zuan");
}
int do_zuan()
{
  object me = this_player();
  if((int)me->query_skill("dodge",1)<10)
    message_vision("$N一彎腰，足尖用力一點地，向瀑布衝過去。結果$N被水流給衝了回來。\n",me);
  else
    {message_vision("$N一彎腰，足尖用力一點地，向瀑布衝過去。$N成功的鑽進了瀑布！\n",me);
     me->move(__DIR__"shdong1");
    }
  return 1;
}