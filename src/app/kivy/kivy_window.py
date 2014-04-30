from kivy.app import App
from kivy.uix.gridlayout import GridLayout
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.modalview import ModalView
from kivy.uix.accordion import Accordion, AccordionItem
from kivy.logger import Logger



class Window(GridLayout):

    def __init__(self, **kwargs):
        super(Window, self).__init__(**kwargs)
        self.cols = 1
        self.username = TextInput(multiline=False)
        self.add_widget(self.username)
        self.password = TextInput(password=True, multiline=False)
        self.add_widget(self.password)

        button = Button(text='Login', font_size=14)
        self.add_widget(button)

        def callMe(self):
			nameis = self.username.select_all()
            print(nameis)
            Logger.debug(nameis)
            Logger.info('title: In call me')

        button.bind(on_press=callMe)


class MyApp(App):

    def build(self):
        return Window()

if __name__ == '__main__':
    MyApp().run()


