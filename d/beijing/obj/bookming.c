// bookming.c

inherit ITEM;

void init()
{
        add_action("do_shake", "doudong");
        add_action("do_shake", "shake");
        add_action("do_shake", "twitter");
}

void create()
{
        set_name("明史輯略", ({"book ming","book","ming"}));
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一本厚厚的書。\n");
                set("unit", "本");
                set("gold", 1);
                set("material", "paper");
        }
        setup();
}


int do_shake(string arg)
{
	object me,goldleaf1,goldleaf2,newbook;
	me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="book"||arg=="ming"||arg=="ming book") 
	{
                if(query("gold") == 1)
		{
								message("vision","突然，幾片金葉從書中掉了出來。\n",environment(me));
                goldleaf1 = new(__DIR__"goldleaf");
                goldleaf1->move(environment(me));
                goldleaf2 = new(__DIR__"goldleaf");
                goldleaf2->move(environment(me));
                set("gold", 0);
                newbook = new(__DIR__"bookming1");
                newbook->move(me);
                destruct(this_object());
    }
		else message("vision","不管怎麼抖，再沒金葉了。\n",environment(me));
	return 1;
	}
}	





