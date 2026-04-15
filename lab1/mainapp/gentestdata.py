import random
from datetime import date, timedelta
from django.db import transaction
from faker import Faker
from .models import Medicine

fk = Faker('ru_RU')

def gentestdata(n=200):
    with transaction.atomic():
        for _ in range(n):
            entry_date = fk.date_between(start_date=date(2020, 1, 1), end_date=date.today())
            expires = entry_date + timedelta(days=random.randint(30, 730))
            
            Medicine.objects.create(
                name=fk.catch_phrase()[:120],
                price=round(random.uniform(50, 4500), 2),
                quantity_in_stock=random.randint(10, 500),
                expiration_date=expires,
                manufacturer=fk.company(),
                requires_prescription=random.choice([True, False]),
                description=fk.text(max_nb_chars=250)
            )
    print(f'Сгенерировано {n} лекарств')