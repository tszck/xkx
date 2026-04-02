// corpse.c

inherit ITEM;

int decayed;

void create()
{
	set_name("無名屍體", ({ "corpse" }) );
	set("long", "這是一具無名屍體。\n");
	set("unit", "具" );
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	decayed = phase;
	switch(phase) {
		case 1:
			say(query("name")+"開始腐爛了，發出一股難聞的惡臭。\n");
			switch(query("gender")) {
				case "男性":
					set_name("腐爛的男屍", ({ "corpse","屍體" }) );
				case "女性":
					set_name("腐爛的女屍", ({ "corpse","屍體" }) );
				default:
					set_name("腐爛的屍體", ({ "corpse","屍體" }) );
			}
			set("long","這具屍體顯然已經躺在這裏有一段時間了，正散發著一股腐屍的味道。\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			say( query("name") + "被風吹乾了，變成一具骸骨。\n" );
			set_name("枯乾的骸骨", ({ "skeleton", "骸骨" }) );
			set("long", "這副骸骨已經躺在這裏很久了。\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			say("一陣風吹過，把"+query("name")+"化成骨灰吹散了。\n");
			if( environment() ) {
				object *inv;
				int i;
				
				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++) 
				{
					if (inv[i]->is_character() && environment()->is_character())
						inv[i]->move(environment(environment()));
					else
						inv[i]->move(environment());
				}
			}
			destruct(this_object());
			break;
	}
}
