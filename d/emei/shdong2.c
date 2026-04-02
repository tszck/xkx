inherit ROOM;
int do_search();
void end(object);
void create()
{
        set("short", "山洞");
        set("long", @LONG
從外洞進入這裏眼前一暗，仔細看時發覺這是一個比
外洞還要大很多的洞穴，四壁上掛滿了硫磺晶體，空氣中
的硫磺味道似要使人窒息。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"shdong1",
        ]));
        set("objects",([
            __DIR__"obj/liuhuang" : 3,
        ]));
	set("coor/x", -6190);
	set("coor/y", -1150);
	set("coor/z", 100);
	setup();
}
void init()
{
        add_action("do_search","search");
}
int do_search()
{
        object me = this_player();
        
        int jing;
        if( me->is_busy() )
                return notify_fail("你上一個動作還沒有完成呢。\n");
        jing=me->query("jing");
        if(jing<30)
                return notify_fail("你無法集中精力查看！\n");
        message_vision("$N開始查看這裏的石壁，希望能找到一塊硫磺。\n",me);
        me->start_busy(2);
        me->set("jing", jing-20);
        call_out("end",3,me);
        return 1;
}
void end(object me)
{
        object ob;
        if(random(2)==0)
                message_vision("$N累了個半死，結果什麼都沒有找到。\n",me);
        else
        {
                ob=new(__DIR__"npc/obj/liuhuang");
                ob->move(me);
                message_vision("$N找到了一塊硫磺，放在身上。\n",me);
        }
 }