from kivy.app import App
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.lang import Builder
from kivy.uix.boxlayout import BoxLayout

Builder.load_file('mytheme.kv')

class Content(BoxLayout):
    def update_text(self, title, paragraph):
        self.ids.title_label.text = title
        self.ids.paragraph_label.text = paragraph

class HomeScreen(Screen):
    def on_enter(self):
        content = self.ids.get('content', None)
        if content:
            content.update_text(
                title="Bem-vindos ao Fórum do Campo Lacaniano BH",
                paragraph="Os Fóruns do Campo Lacaniano (FCL) reúnem psicanalistas e não psicanalistas em diversas cidades em várias partes do mundo. Estes Fóruns estão associados à IF-EPFCL e o seu objetivo principal se deduz ao mesmo tempo de sua origem e dessa referência: contribuir para a presença e a manutenção dos desafios do discurso analítico nas conjunturas do século."
            )

class AgendaScreen(Screen):
    pass

class GalleryScreen(Screen):
    pass

class ContactScreen(Screen):
    pass

class OtherScreen(Screen):
    pass

class MyApp(App):
    def build(self):
        sm = ScreenManager()
        sm.add_widget(HomeScreen(name='home'))
        sm.add_widget(AgendaScreen(name='agenda'))
        sm.add_widget(GalleryScreen(name='gallery'))
        sm.add_widget(ContactScreen(name='contact'))
        sm.add_widget(OtherScreen(name='other'))
        return sm

if __name__ == '__main__':
    MyApp().run()

