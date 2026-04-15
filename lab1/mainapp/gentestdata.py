import random
from datetime import date, timedelta
from django.db import transaction
from faker import Faker
from .models import Medicine

fk = Faker('ru_RU')

def gentestdata():
    with transaction.atomic():
        for _ in range(150):
            entry_date = fk.date_between(start_date=date(2020, 1, 1), end_date=date.today())
            expires = entry_date + timedelta(days=random.randint(30, 730))
            
            med = Medicine(
                name=fk.catch_phrase()[:100],
                price=round(random.uniform(50, 5000), 2),
                quantity_in_stock=random.randint(5, 500),
                expiration_date=expires,
                manufacturer=fk.company(),
                requires_prescription=random.random() > 0.7,
                description=fk.text(max_nb_chars=200)
            )
            med.save()
    print('Сгенерировано 1000 лекарств!')